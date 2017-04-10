#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Polynomial
{
    std::vector<int> a_;

  public:

    Polynomial()
    : a_(1, int())
    {}

    Polynomial(int n)
    : a_(std::max(1, n+1), int())
    {}

    Polynomial(std::initializer_list<int> coeffs)
    : a_{coeffs}
    {}

    int degree() const
    {
        return a_.size()-1;
    }

    bool operator==(Polynomial const & other) const
    {
        return a_ == other.a_;
    }

    int operator[](int i) const
    {
        std::cout << "[] const called" << std::endl;
        return a_[i];
    }

    int & operator[](int i)
    {
        std::cout << "& [] called" << std::endl;
        return a_[i];
    }

    int operator()(int x) const
    {
        int res = a_[degree()];
        for(int k=degree()-1; k>=0; --k)
        {
            res = res*x + a_[k];
        }
        return res;
    }

    Polynomial derivative() const
    {
        Polynomial res(degree()-1);
        for(int k=1; k<=degree(); ++k)
            res[k-1] = k*a_[k];
        return res;
    }

    Polynomial derivative(int d) const
    {
        Polynomial res(*this);
        for(int k=0; k<d; ++k)
            res = res.derivative();
        return res;
    }

    Polynomial operator+(Polynomial const & other) const
    {
        if(degree() < other.degree())
        {
            Polynomial res(other);
            for(int k=0; k<=degree(); ++k)
                res[k] += a_[k];
            return res;
        }
        else
        {
            Polynomial res(*this);
            for(int k=0; k<=other.degree(); ++k)
                res[k] += other.a_[k];
            return res;
        }
    }

    Polynomial operator*(Polynomial const & other) const
    {
        Polynomial res(degree()+other.degree());
        for(int k=0; k<=degree(); ++k)
            for(int l=0; l<=other.degree(); ++l)
                res[k+l] += a_[k]*other.a_[l];
        return res;
    }

    void print()
    {
        std::cout << "{";
        for(int i=0; i<a_.size(); ++i)
        {
            std::cout << " " << a_[i];
        }
        std::cout << "}" << std::endl;
    }
};


int main()
{
    Polynomial p{1,2,3,4};
    p.print();
    p[2] = 9;
    p.print();
    std::cout << p[1] << std::endl;
    int var = p[3];
    std::cout << var << std::endl;
    return 0;
}
