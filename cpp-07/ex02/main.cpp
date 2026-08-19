#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "===== Empty array =====" << std::endl;

    Array<int> empty;

    std::cout << "size: " << empty.size() << std::endl;


    std::cout << "\n===== Int array =====" << std::endl;

    Array<int> numbers(5);

    std::cout << "size: " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    numbers[0] = 42;
    numbers[1] = 21;

    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "numbers[1] = " << numbers[1] << std::endl;


    std::cout << "\n===== Out of bounds =====" << std::endl;

    try
    {
        std::cout << numbers[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught!" << std::endl;
    }


    std::cout << "\n===== Copy constructor =====" << std::endl;

    Array<int> copy(numbers);

    std::cout << "copy[0] before: " << copy[0] << std::endl;

    copy[0] = 100;

    std::cout << "copy[0] after: " << copy[0] << std::endl;
    std::cout << "numbers[0]: " << numbers[0] << std::endl;


    std::cout << "\n===== Assignment operator =====" << std::endl;

    Array<int> assigned(2);

    assigned[0] = 500;
    assigned[1] = 600;

    assigned = numbers;

    std::cout << "assigned size: " << assigned.size() << std::endl;
    std::cout << "assigned[0]: " << assigned[0] << std::endl;

    assigned[0] = 999;

    std::cout << "assigned[0] after: " << assigned[0] << std::endl;
    std::cout << "numbers[0]: " << numbers[0] << std::endl;


    std::cout << "\n===== Const array =====" << std::endl;

    const Array<int> constArray(numbers);

    std::cout << "constArray[0]: " << constArray[0] << std::endl;
    std::cout << "constArray size: " << constArray.size() << std::endl;


    std::cout << "\n===== String array =====" << std::endl;

    Array<std::string> strings(3);

    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "School";

    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << std::endl;


    std::cout << "\n===== Self assignment =====" << std::endl;

    numbers = numbers;

    std::cout << "numbers[0]: " << numbers[0] << std::endl;
    std::cout << "numbers size: " << numbers.size() << std::endl;

    return 0;
}