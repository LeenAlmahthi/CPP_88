
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T &y,int x)
{
    typename T::iterator it = y.begin(); 
    if (y.size() == 0)
          throw std::exception();
    for (unsigned int i = 0; i < y.size(); i++)
    {
        if (y[i] == x)
            return (it);
        it++;
    }
    throw std::exception();
}

#endif