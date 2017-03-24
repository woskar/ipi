#include <string>
#include <iostream>
#include <cassert>

class Point
{
  private:
    // die Koordinaten des Punktes
    double x_;
    double y_;

  public:

    // Standardkonstruktor: initialisiere Punkt (0,0)
    Point()
    : x_(0.0)
    , y_(0.0)
    {}

    // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point(double x, double y)
    : x_(x)
    , y_(y)
    {}

    // Getter-Funktionen fuer die Koordinaten
    double x() const
    {
        return (*this).x_;
    }

    double y() const
    {
        return (*this).y_;
    }

    // teste ob zwei Punkte gleich sind
    bool operator==(Point const & other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    // teste ob zwei Punkte ungleich sind
    bool operator!=(Point const & other) const
    {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // erzeuge neuen Punkt, desssen x- und y-Koordinate
    // vertauscht sind
    Point transpose() const
    {
        Point res((*this).y(), (*this).x());
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point translate(Point const & v) const
    {
        Point res((*this).x() + v.x(), (*this).y() + v.y());
        return res;
    }
};

// wandle den Punkt in einen String der Form "[x, y]"
std::string to_string(Point const & p)
{
    return "[" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + "]";
}

// zwei Punkte im Sinne der Vektoraddition addieren
Point operator+ (Point p1, Point p2)
{
    return Point(p1.x()+p2.x(), p1.y()+p2.y());
}

// zwei Punkte im Sinne der Vektoraddition subtrahieren
Point operator- (Point p1, Point p2)
{
    return Point(p1.x()-p2.x(), p1.y()-p2.y());
}

//elemnweise Multiplikation von Punkten
Point operator* (Point p1, Point p2)
{
    return Point(p1.x()*p2.x(), p1.y()*p2.y());
}

//elemnweise Division von Punkten
Point operator/ (Point p1, Point p2)
{
    return Point(p1.x()/p2.x(), p1.y()/p2.y());
}

// Punkt skalieren
Point operator*(Point p, double s)
{
    return Point(p.x()*s, p.y()*s);
}

Point operator*(double s, Point p)
{
    return Point(s*p.x(), s*p.y());
}

// Punkt skalieren
Point operator/(Point p, double s)
{
    return Point(p.x()/s, p.y()/s);
}

// Punktspiegelung am Ursprung
Point operator-(Point p)
{
    return Point(-p.x(), -p.y());
}


void test_Point()
{
    typedef Point P; // neuer kurzer Name für 'Point'

    P p0;
    assert(p0.x() == 0);
    assert(p0.y() == 0);

    // fuegen Sie Tests der arithmetischen Operationen hinzu

    // a) Vektoraddition von Punkten
    Point p(2.0, 3.0), q(4.0, 5.0);
    Point r = p+q;
    assert(r == Point(6.0, 8.0));

    Point p1(1.1, 1.5), q1(2.0, 3.0);
    Point r1 = p1 + q1;
    assert(r1 == Point(3.1, 4.5));

    Point r2 = p1 + q;
    assert(r2 == Point(5.1, 6.5));

    Point r3 = p-q;
    assert(r3 == Point(-2.0, -2.0));

    Point r4 = q - p;
    assert(r4 == Point(2.0, 2.0));

    Point r5 = p1-q;
    assert(r5 == Point(-2.9, -3.5));

    Point p2(2.3, 3.1), q2(4.2, 5.8);
    Point r6 = p*q;
    assert(r6 == Point(8.0, 15.0));

    Point r7 = p1 * q1;
    assert(r7 == Point(2.2, 4.5));

    Point r8 = p0 * p1;
    assert(r8 == Point(0.0, 0.0));

    Point r9 = p/q;
    assert(r9 == Point(2.0/4.0, 3.0/5.0));

    Point r10 = 3.0*p;
    assert(r10 == Point(6.0, 9.0));

    Point r11 = 4.0*p;
    assert(r11 == Point(8.0, 12.0));

    Point r12 = 5.0*p;
    assert(r12 == Point(10.0, 15.0));

    Point r13 = p*3.0;
    assert(r13 == Point(6.0, 9.0));

    Point r14 = p*4.0;
    assert(r14 == Point(8.0, 12.0));

    Point r15 = p*5.0;
    assert(r15 == Point(10.0, 15.0));

    Point r16 = r/2.0;
    assert(r16 == Point(3.0, 4.0));

    Point r17 = -p;
    assert(r17 == Point(-2.0, -3.0));


    std::cout << "Alle Tests erfolgreich.\n";
}

int main()
{
    test_Point();
}
