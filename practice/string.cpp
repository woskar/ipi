#include <iostream>
#include <string>
#include <vector>

void foo(int &a)
{
    a += 3;
}

int main()
{
    std::string a = "abc";
    std::string b = a + "def";
    std::cout << b << std::endl;
    std::string c(b, 1, 3);
    std::cout << c << std::endl;

    int d = 2;
    //const int * pd = &d;
    foo(d);
    std::cout << d << std::endl;

    std::vector<int> v = {1,2,3,4,5,6,7};
    for(int & i : v)
    {
        std::cout << i << std::endl;
    }

    int e = 2;

    return 0;
}
