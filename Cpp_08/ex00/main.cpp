#include <iostream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(0);
    v.push_back(42);

    try
    {
        std::cout << *easyfind(v, 10) << "\n";
        std::cout << *easyfind(v, 0) << "\n";
        std::cout << *easyfind(v, 42) << "\n";
        std::cout << *easyfind(v, 11) << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Element not found" << "\n";
    }

    return 0;
}