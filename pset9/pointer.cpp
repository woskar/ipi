//This is just a personal note on pointers:

#include <iostream>

void swap1(int a, int b);
void swap2(int *a, int *b);

int main()
{
    int x = 1;
    int y = 2;

    swap1(x,y);
    std::cout << "x is " << x << " y is " << y << std::endl;

    swap2( &x, &y);
    std::cout << "x is " << x << " y is " << y << std::endl;
}

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
