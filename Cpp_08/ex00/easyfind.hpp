
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &y, int x)
{
    typename T::iterator it = std::find(y.begin(), y.end(), x);

    if (it == y.end())
        throw std::exception();

    return it;
}

#endif