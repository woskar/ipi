#include <iostream>
#include <vector>

template<typename T>
T ggt(T a, T b)
{
    if(b == T())
        return a;
    else
        return ggt(b, a%b);
}

void test()
{
    std::cout << "hello" << std::endl;
}

template<typename T>
class Rational
{
private:
    T num_;
    T denom_;

public:
    Rational(): num_(0), denom_(1){}
    Rational(T zahl): num_(zahl), denom_(1){}
    Rational(T one, T two): num_(one), denom_(two)
    {
        normalize(ggt(num_, denom_));
    }

    T getNum() const {return num_;}
    T getDenom() const {return denom_;}

    void normalize(T ggt)
    {
        if(denom_ < 0)
        {
            num_ = -num_;
            denom_ = -denom_;
        }
        if(num_ == T())
        {
            *this = Rational();
        }
        else
        {
            num_ /= abs(ggt);
            denom_ /= abs(ggt);
        }
    }
};

template <typename T>
std::string to_string(const Rational<T> & r)
{
    return std::to_string(r.getNum()) + "/" + std::to_string(r.getDenom());
}

template <typename T>
Rational<T> operator*(const Rational<T> & rational, T number)
{
    T num = rational.getNum() * number;
    T denom = rational.getDenom();
    return Rational<T>(num, denom);
}

template <typename T>
Rational<T> operator*(const Rational<T> & one, const Rational<T> & other)
{
    T num = one.getNum() * other.getNum();
    T denom = one.getDenom() * other.getDenom();
    return Rational<T>(num, denom);
}

template <typename T>
Rational<T> operator*(T n, const Rational<T> & other)
{
    T num = n * other.getNum();
    T denom = other.getDenom();
    return Rational<T>(num, denom);
}

template <typename T>
bool less(const Rational<T> & r1, const Rational<T> & r2)
{
    return (double(r1.getNum())/double(r1.getDenom()))
             < (double(r2.getNum())/double(r2.getDenom()));
}

int main()
{
    //std::cout << ggt(30, 9) << std::endl;

    typedef Rational<int> R;
    R r1, r2(2), r3(3,4), r4(0,4), r5(2,4), r6(-6, -2), r7(6, -4);
    std::cout << to_string(r1) << std::endl;
    std::cout << to_string(r2) << std::endl;
    std::cout << to_string(r3) << std::endl;
    std::cout << to_string(r4) << std::endl;
    std::cout << to_string(r5) << std::endl;
    std::cout << to_string(r6) << std::endl;
    std::cout << to_string(r7) << std::endl;
    std::cout << to_string(r1 * r2) << std::endl;
    std::cout << to_string(r2 * r3) << std::endl;
    std::cout << to_string(r2 * r7) << std::endl;
    std::cout << to_string(r3 * 2) << std::endl;
    std::cout << to_string(-4 * r3) << std::endl;
    std::cout << std::endl;

    std::vector<R> a = {r1, r2, r3, r4, r5, r6, r7};

    sort(a.begin(), a.end(), [](R r1, R r2){return less(r1, r2);});
    for(std::vector<R>::iterator it = a.begin(); it!=a.end(); ++it)
        std::cout << to_string(*it) << std::endl;

    std::cout << std::endl;

    sort(a.begin(), a.end(), [](R r1, R r2){return less(r2, r1);});
    for(std::vector<R>::iterator it = a.begin(); it!=a.end(); ++it)
        std::cout << to_string(*it) << std::endl;

    return 0;
}
