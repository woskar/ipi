#include <iostream>
#include <vector>


class Polynomial
{
private:
    std::vector<int> a_;

public:
    Polynomial(): a_(1, int()){}

    Polynomial(std::initializer_list<int> list): a_{list}{}
};


int main()
{
    Polynomial p{1,2,3,4};
    return 0;
}
