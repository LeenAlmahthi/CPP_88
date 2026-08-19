#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "===== Basic test =====" << std::endl;

    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "===== Iterator test =====" << std::endl;

    Span sp2(10);

    int numbers[] = {10, 20, 30, 40, 50};

    sp2.addNumbers(numbers, numbers + 5);

    std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp2.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "===== 10000 numbers test =====" << std::endl;

    std::vector<int> big;

    for (int i = 0; i < 10000; i++)
        big.push_back(i);

    Span sp3(10000);

    sp3.addNumbers(big.begin(), big.end());

    std::cout << "Size: " << sp3.size() << std::endl;
    std::cout << "Shortest: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp3.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "===== Full Span test =====" << std::endl;

    try
    {
        sp.addNumber(100);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: Span is full" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "===== Not enough numbers =====" << std::endl;

    try
    {
        Span empty(5);
        empty.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: not enough numbers" << std::endl;
    }

    return 0;
}