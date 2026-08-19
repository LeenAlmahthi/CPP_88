#include <iostream>
#include "iter.hpp"

int add(int &n)
{
    return (n++);
}

int main(void)
{
    int n[] = {0, 1, 2, 3, 4};

    std::cout << "before add" << std::endl;
    for (int i=0; i < 5 ;i++)
         std::cout << "  " << n[i] <<  std::endl;
    
    ::iter(n, 5, add);

    std::cout << "After add" << std::endl;
    for (int i=0; i < 5 ;i++)
         std::cout << "  " << n[i] <<  std::endl;

    return 0;
}