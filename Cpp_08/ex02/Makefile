NAME = Mutated

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp MutantStack.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all