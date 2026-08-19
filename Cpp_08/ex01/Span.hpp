#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int        _max;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(int number);
    template <typename T>
    void addNumbers(T start, T end)
    {
        while (start != end)
        {
            addNumber(*start);
            ++start;
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int size() const;
};

#endif