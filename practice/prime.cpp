#include <iostream>

int main()
{
    int n;
    std::cout << "Please insert an integer: ";
    std::cin >> n;
    std::cout << n << " : " << std::flush;

    int i = 2;
    while(i <= n)
    {
        if(n%i == 0)
        {
            std::cout << i << " " << std::flush;
            n /= i;
            i = 2;
        }
        else
            ++i;
    }
    std::cout << std::endl;
    return 0;
}
