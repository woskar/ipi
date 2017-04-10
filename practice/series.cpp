#include <cmath>
#include <iostream>

double series(double x, int n)
{
    double sum = 0;
    for(int k = 1; k <= n; ++k)
        sum += exp(-k*x)/double(k*k);
    return sum;
}

int main()
{
    double x;
    int n;
    std::cout << "Please insert real number x: " << std::flush;
    std::cin >> x;
    std::cout << "Please insert integer n: ";
    std::cin >> n;
    std::cout << "The series evaluates to: " << series(x,n) << std::endl;

    return 0;
}
