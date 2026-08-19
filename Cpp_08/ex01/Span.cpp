#include "Span.hpp"

Span::Span(unsigned int N) : _max(N)
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max = other._max;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _max)
        throw std::runtime_error("Out Of bounds");

    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    unsigned int shortest = tmp[1] - tmp[0];

    for (unsigned int i = 1; i < tmp.size(); i++)
    {
        unsigned int distance = tmp[i] - tmp[i - 1];

        if (distance < shortest)
            shortest = distance;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    return tmp[tmp.size() - 1] - tmp[0];
}

unsigned int Span::size() const
{
    return _numbers.size();
}