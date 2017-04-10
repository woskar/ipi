#include <iostream>

int main()
{
    const int p[3] = {1,2,3};
    int q = * p;
    std::cout << p << std::endl;
    std::cout << q << std::endl;
    return 0;
}
