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

Point operator+(Point p1, Point p2)
{
    Point res(p1.x()+p2.x(), p1.y()+p2.y());
    return res;
}

Point operator-(Point p1, Point p2)
{
    Point res(p1.x()-p2.x(), p1.y()-p2.y());
    return res;
}

Point operator-(Point p)
{
    Point res(-p.x(), -p.y());
    return res;
}

Point operator*(Point p1, Point p2)
{
    Point res(p1.x()*p2.x(), p1.y()*p2.y());
    return res;
}

Point operator*(double s, Point p)
{
    Point res(s*p.x(), s*p.y());
    return res;
}

Point operator*(Point p, double s)
{
    Point res(p.x()*s, p.y()*s);
    return res;
}

Point operator/(Point p1, Point p2)
{
    Point res(p1.x()/p2.x(), p1.y()/p2.y());
    return res;
}

Point operator/(Point p, double d)
{
    Point res(p.x()/d, p.y()/d);
    return res;
}

void test_Point_double()
{
    typedef Point P; // neuer kurzer Name für 'Point'

    P p;
    assert(p.x() == 0);
    assert(p.y() == 0);

    // fuegen Sie Tests hinzu

    std::cout << "Alle Tests erfolgreich.\n";
}

int main()
{
    test_Point_double();
}
