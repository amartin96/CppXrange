// TODO: Make sentinel end iterator

#include <iostream>
#include "xrange.h"

int main()
{
    for (auto i : xrange<int>(0, 1000000, 1))
    {
        std::cout << i << std::endl;
    }

    return 0;
}