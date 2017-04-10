#include <iostream>

int foo(int & x)
{
    x+= 1;
    std::cout << "x is now " << x << std::endl;
    return x * 2;
}

int main()
{
    int i = 6;
    int j = foo(i);
    std::cout << "i is now " << i << " and j is " << j << std::endl;
    return 0;
}
