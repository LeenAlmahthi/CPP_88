#ifndef  WHATEVER_HPP 
#define WHATEVER_HPP

template <typename t>
void swap(t &x ,t &y)
{
    t q = x; 
    x = y;
    y = q;
}
template <typename t>
t min(t x, t y)
{
    if (x < y)
        return (x);
    return (y);
} 
template <typename t>
t max(t x, t y)
{
    if (x > y)
        return (x);
    return (y);
} 
#endif