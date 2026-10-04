#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>

int		count = 0, max_fd = 0;    // count : for the id to the clinet 
int		ids[65536];  // we use it for the select  it will check from the fd to the max the fs  what the fd apply to handel it 
char	*msgs[65536]; 

// Id client -- fds client  [1] = 5;   1: fd  5: id client 

fd_set	rfds, wfds, afds;  //read [will ready to read will put here ] write [will ready to write will put here ] master set[put all the fds to monter the fds]
char	buf_read[1001], buf_write[42];  


// START COPY-PASTE FROM GIVEN MAIN

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

// END COPY-PASTE


void	fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	notify_other(int author, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != author)
			send(fd, str, strlen(str), 0);
	}
}

void	register_client(int fd)
{
	if (fd > max_fd )
		max_fd = fd;
	// max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);  // copy this message to the buf 
	notify_other(fd, buf_write);
}

void	remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	notify_other(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}

void	send_msg(int fd)
{
	char *msg;

	while (extract_message(&(msgs[fd]), &msg))   // when it finds a \n will send it 
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		notify_other(fd, buf_write);
		notify_other(fd, msg);
		free(msg);
	}
}

int		create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0); // we put the max_fd with a # of a fd 
	if (max_fd < 0)
		fatal_error();
	FD_SET(max_fd, &afds); // add this fd to the afds to monetor it 
	return max_fd;
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	FD_ZERO(&afds); // clean the fds  || with address
	int sockfd = create_socket();

	// START COPY-PASTE FROM MAIN

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));  // reset the fds 

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // this the local host but write in anther formatte 
	servaddr.sin_port = htons(atoi(av[1])); // replace 8080

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))
		fatal_error();
	if (listen(sockfd, SOMAXCONN)) // the main uses 10, SOMAXCONN is 180 on my machine
		fatal_error();

	// END COPY-PASTE

	while (1)
	{
		rfds = wfds = afds; // first will put all the fds then select will remove from the rfds the fds that not be read 

		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0) // must remember it not fount in man 
			fatal_error();

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))  // are the fd in the rfds 
				continue;

			if (fd == sockfd)
			{
				socklen_t addr_len = sizeof(servaddr);
				int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len); // must usr a cast (struct sockaddr *) 
				if (client_fd >= 0) // valid clinet we will add it to the fds 
				{
					register_client(client_fd);
					break ;
				}
			}
			else
			{
				int read_bytes = recv(fd, buf_read, 1000, 0);
				if (read_bytes <= 0) // fail 
				{
					write (1,"test\n",5);
					remove_client(fd);
					break ;
				}
				buf_read[read_bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
				write (1,"read\n",5);
			}
		}
	}
	return 0;
}
