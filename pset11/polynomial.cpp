#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>


class Polynomial
{
    std::vector<int> a_;

  public:

        // Konstruktor, dem die Koeffizienten als C-Array
        // uebergeben werden koennen, z.B.:
        //
        //     Polynomial p{1, 2, 3};
    Polynomial(std::initializer_list<int> coeffs)
    : a_{coeffs}
    {}

        // Konstruktor fuer ein Polynom vom Grad 0 (nur der konstante
        // Koeffizient ist definiert und hat den Wert 0).
    Polynomial()
    : a_(1, int()) // IHR CODE HIER
    {}

        // Konstruktor fuer ein Polynom vom Grad n, bei dem alle
        // Koeffizienten 0 sind. Der Fall n < 0 soll wie n == 0 behandelt
        // werden.
    Polynomial(int n)
    : a_(std::max(1, n+1), int()) // IHR CODE HIER
    {}

        // Grad des Polynoms (Exponent der hoechsten vorkommenden Potenz)
    int degree() const
    {
        return a_.size() - 1;// IHR CODE HIER
    }

        // lesender Zugriff auf den Koeffizienten zur Potenz i
    int operator[](int i) const
    {
        return a_[i]; // IHR CODE HIER
    }

        // Lese-/Schreib-Zugriff auf den Koeffizienten zur Potenz i
    int & operator[](int i)
    {
        return a_[i]; // IHR CODE HIER
    }

        // Ausrechnen des Polynoms fuer das Argument x
    int operator()(int x) const
    {
        /*
        int res = 0;
        for(int i=0, n=a_.size(); i<n; ++i)
        {
            res += a_[i]*std::pow(x, i);
        }
        */
        // more efficient:
        // scheme: ((((a3)*x + a2)*x + a1 )*x + a0) = a3x^3 + a2x^2 + a1x + a0
        int res = a_[degree()]; //start with hightest coefficient
        for(int k = degree()-1; k >= 0; --k)//go from inner bracket to outer
        {
            res = res*x + a_[k]; // multiply and sum
        }
        return res;
    }

    // weitere Funktionen
    // IHR CODE HIER

    bool operator==(Polynomial const & q)
    {
        return a_ == q.a_;
    }

    Polynomial derivative() const
    {
        Polynomial deriv(degree()-1);
        for(int i=1; i<=degree(); ++i)
            deriv[i-1] = a_[i]*i;
        return deriv;
    }

    Polynomial derivative(int t) const
    {
        Polynomial deriv(*this);
        for(int i=0; i<t; ++i)
            deriv = deriv.derivative();
        return deriv;
    }

    Polynomial operator+(Polynomial const & other)
    {
        int deg1 = (*this).degree();
        int deg2 = other.degree();
        int deg3 = std::max(deg1, deg2);
        Polynomial result(deg3);

        // determine the larger Polynomial
        if(deg1 > deg2)
        {
            // Iterate over resulting polynomial
            for(int i=0; i<=deg3; ++i)
            {
                // If i smaller than small polynomial, add together
                if(i<=deg2)
                    result[i] = (*this)[i] + other[i];
                // Otherwise copy value from larger polynomial
                else
                    result[i] = (*this)[i];
            }
        }

        else
        {
            // Iterate over resulting polynomial
            for(int i=0; i<=deg3; ++i)
            {
                // If i smaller than small polynomial, add together
                if(i<=deg1)
                    result[i] = (*this)[i] + other[i];
                // Otherwise copy value from larger polynomial
                else
                    result[i] = other[i];
            }
        }
    return result;
    }

    Polynomial operator*(Polynomial const & other)
    {
        Polynomial result(degree()+other.degree());
        for(int i=0; i<=degree(); ++i)
        {
            Polynomial res(other.degree()+i);
            for(int j=0; j<=other.degree(); ++j)
                res[i+j] = (*this)[i] * other[j];
            result = result + res;
        }
        return result;
    }
};


int main()
{
        // testen des Standard-Konstruktors
    Polynomial p0;
    assert(p0.degree() == 0);
    assert(p0[0] == 0);

        // testen des Konstruktors mit Gradangabe
    Polynomial pm(-1);
    assert(pm == p0);

    Polynomial p2(2);
    assert(p2.degree() == 2);

        // testen des Konstruktors mit Koeffizientenarray
    Polynomial p{1, 2, 3};
    assert(p.degree() == 2);

        // testen der Werte der Koeffizienten
    assert(p2[0] == 0);
    assert(p2[1] == 0);
    assert(p2[2] == 0);

    assert(p[0] == 1);
    assert(p[1] == 2);
    assert(p[2] == 3);

        // testen, dass die Polynome fuer verschiedene Argumente x
        // korrekt ausgerechnet werden
    assert(p0(1) == 0);
    assert(p0(2) == 0);
    assert(p0(3) == 0);

    assert(p2(1) == 0);
    assert(p2(2) == 0);
    assert(p2(3) == 0);

    assert(p(1) == 6);
    assert(p(2) == 17);
    assert(p(3) == 34);

        // testen der ersten Ableitung
    Polynomial derivative1_expected{2, 6};
    assert(p.derivative()  == derivative1_expected);
    assert(p.derivative(1) == derivative1_expected);

        // testen der zweiten bis vierten Ableitung
    Polynomial derivative2_expected{6};
    assert(p.derivative(2)  == derivative2_expected);
    Polynomial derivative3_expected{0};
    assert(p.derivative(3)  == derivative3_expected);
    assert(p.derivative(4)  == derivative3_expected);

        // testen der Polynom-Addition
    Polynomial pa1 = p + p;
    Polynomial pa1_expected{2, 4, 6};
    assert(pa1 == pa1_expected);

    Polynomial pa2 = p + Polynomial{3, 6};
    Polynomial pa2_expected{4, 8, 3};
    assert(pa2 == pa2_expected);

        // testen der Polynom-Multiplikation
    Polynomial pm1 = p * p;
    assert(pm1.degree() == 4);
    assert(pm1(2) == p(2)*p(2));
    Polynomial pm1_expected{1, 4, 10, 12, 9};
    assert(pm1 == pm1_expected);

    Polynomial pm2 = p * Polynomial{2, 6};
    assert(pm2.degree() == 3);
    Polynomial pm2_expected{2, 10, 18, 18};
    assert(pm2 == pm2_expected);

    std::cout << "Alle Tests erfolgreich!\n";
}
