#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 30);

        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 99);

        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}