#include <string>
#include <iostream>
#include <cassert>

template <typename CoordinateType>
class Point
{
  private:
    // die Koordinaten des Punktes
    CoordinateType x_;
    CoordinateType y_;

  public:

    // Standardkonstruktor: initialisiere Punkt (0,0)
    Point<CoordinateType>()
    : x_(0.0)
    , y_(0.0)
    {}

    // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point<CoordinateType>(CoordinateType x, CoordinateType y)
    : x_(x)
    , y_(y)
    {}

    // Getter-Funktionen fuer die Koordinaten
    CoordinateType x() const
    {
        return (*this).x_;
    }

    CoordinateType y() const
    {
        return (*this).y_;
    }

    // teste ob zwei Punkte gleich sind
    bool operator==(Point<CoordinateType> const & other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    // teste ob zwei Punkte ungleich sind
    bool operator!=(Point<CoordinateType> const & other) const
    {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // erzeuge neuen Punkt, desssen x- und y-Koordinate
    // vertauscht sind
    Point<CoordinateType> transpose() const
    {
        Point<CoordinateType> res((*this).y(), (*this).x());
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point<CoordinateType> translate(Point<CoordinateType> const & v) const
    {
        Point<CoordinateType> res((*this).x() + v.x(), (*this).y() + v.y());
        return res;
    }
};


// wandle den Punkt in einen String der Form "[x, y]"
template <typename CoordinateType>
std::string to_string(Point<CoordinateType> const & p)
{
    return "[" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + "]";
}

template <typename CoordinateType>
Point<CoordinateType> operator+(Point<CoordinateType> p1, Point<CoordinateType> p2)
{
    Point<CoordinateType> res(p1.x()+p2.x(), p1.y()+p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType>  operator-(Point<CoordinateType>  p1, Point<CoordinateType>  p2)
{
    Point<CoordinateType> res(p1.x()-p2.x(), p1.y()-p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator-(Point<CoordinateType> p)
{
    Point<CoordinateType> res(-p.x(), -p.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator*(Point<CoordinateType> p1, Point<CoordinateType> p2)
{
    Point<CoordinateType> res(p1.x()*p2.x(), p1.y()*p2.y());
    return res;
}


template <typename CoordinateType>
Point<CoordinateType> operator*(CoordinateType s, Point<CoordinateType> p)
{
    Point<CoordinateType> res(s*p.x(), s*p.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator*(Point<CoordinateType> p, CoordinateType s)
{
    Point<CoordinateType> res(p.x()*s, p.y()*s);
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator/(Point<CoordinateType> p, CoordinateType d)
{
    Point<CoordinateType> res(p.x()/d, p.y()/d);
    return res;
}


template <typename CoordinateType>
Point<CoordinateType> operator/(Point<CoordinateType> p1, Point<CoordinateType> p2)
{
    Point<CoordinateType> res(p1.x()/p2.x(), p1.y()/p2.y());
    return res;
}



void test_Point_double()
{
    typedef Point<double> P;// neuer kurzer Name für 'Point'

    P p0;
    assert(p0.x() == 0);
    assert(p0.y() == 0);

    // fuegen Sie Tests hinzu


    P p(2.0, 3.0), q(4.0, 5.0);
    P r = p+q;
    assert(r == P(6.0, 8.0));

    P p1(1.1, 1.5), q1(2.0, 3.0);
    P r1 = p1 + q1;
    assert(r1 == P(3.1, 4.5));

    P r2 = p1 + q;
    assert(r2 == P(5.1, 6.5));

    P r3 = p-q;
    assert(r3 == P(-2.0, -2.0));

    P r4 = q - p;
    assert(r4 == P(2.0, 2.0));

    P r5 = p1-q;
    assert(r5 == P(-2.9, -3.5));

    P p2(2.3, 3.1), q2(4.2, 5.8);
    P r6 = p*q;
    assert(r6 == P(8.0, 15.0));

    P r7 = p1 * q1;
    assert(r7 == P(2.2, 4.5));

    P r8 = p0 * p1;
    assert(r8 == P(0.0, 0.0));

    P r9 = p/q;
    assert(r9 == P(2.0/4.0, 3.0/5.0));

    P r10 = 3.0*p;
    assert(r10 == P(6.0, 9.0));

    P r11 = 4.0*p;
    assert(r11 == P(8.0, 12.0));

    P r12 = 5.0*p;
    assert(r12 == P(10.0, 15.0));

    P r13 = p*3.0;
    assert(r13 == P(6.0, 9.0));

    P r14 = p*4.0;
    assert(r14 == P(8.0, 12.0));

    P r15 = p*5.0;
    assert(r15 == P(10.0, 15.0));

    P r16 = r/2.0;
    assert(r16 == P(3.0, 4.0));

    P r17 = -p;
    assert(r17 == P(-2.0, -3.0));


    std::cout << "Alle double Tests erfolgreich.\n";
}

typedef Point<int> Pi;
void test_Point_int()
{
    //typedef Point P; // neuer kurzer Name für 'Point'

    Pi p0;
    assert(p0.x() == 0);
    assert(p0.y() == 0);

    // fuegen Sie Tests hinzu


    Pi p(20, 30), q(40, 50);
    Pi r = p+q;
    assert(r == Pi(60, 80));

    Pi p1(11, 15), q1(20, 30);
    Pi r1 = p1 + q1;
    assert(r1 == Pi(31, 45));

    Pi r2 = p1 + q;
    assert(r2 == Pi(51, 65));

    Pi r3 = p-q;
    assert(r3 == Pi(-20, -20));

    Pi r4 = q - p;
    assert(r4 == Pi(20, 20));

    Pi r5 = p1-q;
    assert(r5 == Pi(-29, -35));

    Pi p2(23, 31), q2(42, 58);
    Pi r6 = p*q;
    assert(r6 == Pi(800, 1500));

    Pi r7 = p1 * q1;
    assert(r7 == Pi(220, 450));

    Pi r8 = p0 * p1;
    assert(r8 == Pi(00, 00));

    Pi r9 = p/q;
    assert(r9 == Pi(20/40, 30/50));

    Pi r10 = 30*p;
    assert(r10 == Pi(600, 900));

    Pi r11 = 40*p;
    assert(r11 == Pi(800, 1200));

    Pi r12 = 50*p;
    assert(r12 == Pi(1000, 1500));

    Pi r13 = p*30;
    assert(r13 == Pi(600, 900));

    Pi r14 = p*40;
    assert(r14 == Pi(800, 1200));

    Pi r15 = p*50;
    assert(r15 == Pi(1000, 1500));

    Pi r16 = r/20;
    assert(r16 == Pi(3, 4));

    Pi r17 = -p;
    assert(r17 == Pi(-20, -30));


    std::cout << "Alle int Tests erfolgreich.\n";
}

int main()
{
    try
    {
        test_Point_double();
        test_Point_int();
        return 0;
    }
    catch(std::exception & e)
    {
        std::cout << "Es gab einen Fehler vom Typ:" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
}
