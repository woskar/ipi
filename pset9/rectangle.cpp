#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

/////////////////////////////////////////////////
// die 2-dimensionale Punkt-Klasse aus der Vorlesung
class Point
{
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

    // erzeuge neuen Punkt, dessen x- und y-Koordinate
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

/////////////////////////////////////////////////
// Implementieren Sie die Rectangle-Klasse.
class Rectangle
{
    Point p0_; // linke untere Ecke
    Point p1_; // rechte obere Ecke

  public:

    // Standardkonstruktor: entartetes Rechteck am Punkt (0,0)
    Rectangle()
    : p0_(0.0, 0.0)
    , p1_(0.0, 0.0)
    {}

    // Rechteck von Punkt (0,0) bis p1
    Rectangle(Point const & p1)
    : p0_(0.0, 0.0)
    , p1_(p1)
    {}

    // Rechteck von Punkt p0 zu Punkt p1
    Rectangle(Point const & p0, Point const & p1)
    : p0_(p0)
    , p1_(p1)
    {}

    // read-only Getter-Funktionen fuer die Member-Variablen
    Point const & p0() const
    {
        return (*this).p0_;
    }

    Point const & p1() const
    {
        return (*this).p1_;
    }

    // Implementieren Sie die folgenden Getter-Funktionen.
    double x0() const // linke x-Koordinate
    {
        return (*this).p0_.x();
    }

    double x1() const // rechte x-Koordinate
    {
        return (*this).p1_.x();
    }

    double y0() const // untere y-Koordinate
    {
        return (*this).p0_.y();
    }

    double y1() const // obere  y-Koordinate
    {
        return (*this).p1_.y();
    }

    double width() const  // Breite
    {
        return (*this).p1_.x()-(*this).p0_.x();
    }

    double height() const // Hoehe
    {
        return (*this).p1_.y()-(*this).p0_.y();
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck nicht ungueltig ist.
    bool is_valid() const
    {
        if((*this).height() >= 0 && (*this).width() >= 0)
            return true;
        else
            return false;
    }

    // Implementieren Sie eine Funktion, die die Flaeche des
    // Rechtecks zurueckgibt, bzw. -1.0, wenn das Rechteck
    // ungueltig ist.
    double area() const
    {
        return is_valid()? width() * height() : -1;
    }

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, bei dem die x- und y-Koordinaten vertauscht sind.
    Rectangle transpose() const
    {
        Point p0((*this).p0().y(), (*this).p0().x());
        Point p1((*this).p1().y(), (*this).p1().x());

        Rectangle res(p0, p1);
        return res;
    }

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, das um den Vektor v verschoben ist.
    Rectangle translate(Point const & v) const
    {
        Point p0((*this).p0().x()+v.x(), (*this).p0().y()+v.y());
        Point p1((*this).p1().x()+v.x(), (*this).p1().y()+v.y());
        Rectangle res(p0, p1);
        return res;
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn der Punkt p im Rechteck (*this) enthalten
    // ist. Wenn (*this) ungueltig ist, soll 'false' zurueckgegeben
    // werden.
    bool contains(Point const & p) const
    {
        if(p.x() >= (*this).p0().x() &&
           p.x() <= (*this).p1().x() &&
           p.y() >= (*this).p0().y() &&
           p.y() <= (*this).p1().y() )
            return true;
        else
            return false;
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck r im Rechteck (*this) enthalten
    // ist. Wenn (*this) oder r ungueltig sind, soll 'false' zurueckgegeben
    // werden.
    bool contains(Rectangle const & r) const
    {
        if( r.is_valid() && (*this).is_valid() &&
            (*this).contains(r.p0()) &&
            (*this).contains(r.p1()) )
            return true;
        else
            return false;
    }

    bool operator==(Rectangle other) const
    {
        return (*this).p0().x()==other.p0().x() && (*this).p0().y()==other.p0().y() && (*this).p1().x()==other.p1().x() && (*this).p1().y()==other.p1().y();
    }

    bool operator!=(Rectangle other) const
    {
        return (*this).p0().x()!=other.p0().x() || (*this).p0().y()!=other.p0().y() || (*this).p1().x()!=other.p1().x() || (*this).p1().y()!=other.p1().y();
    }

};

// Implementieren Sie eine Funktion, die das Rechteck
// in einen String der Form "[x0:x1, y0:y1]" umwandelt.
std::string to_string(Rectangle const & r)
{
    return ("[" + std::to_string(r.x0()) + ":"
                     + std::to_string(r.x1()) + ", "
                     + std::to_string(r.y0()) + ":"
                     + std::to_string(r.y1()) + "]");
}

// Implementieren Sie eine Funktion, die das kleinste Rechteck
// zurueckgibt, das r1 und r2 enthaelt.
Rectangle rectangle_union(Rectangle const & r1, Rectangle const & r2)
{
    double minx0 = std::min(r1.p0().x(), r2.p0().x());
    double miny0 = std::min(r1.p0().y(), r2.p0().y());
    double maxx1 = std::max(r1.p1().x(), r2.p1().x());
    double maxy1 = std::max(r1.p1().y(), r2.p1().y());

    Rectangle res(Point(minx0, miny0), Point(maxx1, maxy1));
    return res;
}

// Implementieren Sie eine Funktion, die den Durchschnitt
// der Rechtecke r1 und r2 zerueckgibt, oder ein beliebiges
// ungueltiges Rechteck, falls r1 und r2 nicht ueberlappen.
Rectangle rectangle_intersection(Rectangle const & r1, Rectangle const & r2)
{
    double minx0 = std::min(r1.p1().x(), r2.p0().x());
    double miny0 = std::min(r1.p1().y(), r2.p0().y());
    double maxx1 = std::max(r1.p1().x(), r2.p0().x());
    double maxy1 = std::max(r1.p1().y(), r2.p0().y());

    Rectangle res(Point(minx0, miny0), Point(maxx1, maxy1));
    return res;
}

// Implementieren Sie Tests fuer die Rectangle-Klasse.
void testRectangle()
{
    Rectangle r0(Point(3.0, 5.0));

    assert(r0.p0() == Point(0.0, 0.0));
    assert(r0.p1() == Point(3.0, 5.0));

    Rectangle r(Point(1.0, 2.0), Point(3.0, 5.0));

    assert(r.x0() == 1.0);

    // Fuegen Sie weitere Tests entsprechend der Aufgabe hinzu.

    // Aufgabe b) Konstruktor und Getter Test

    Rectangle r1;
    Rectangle r2(Point(1.0, 1.0));
    Rectangle r3(Point(2.0, 2.0), Point(4.0, 4.0));
    Rectangle r4(Point(2.0, 1.0), Point(-1.0, 0.0));

    assert(r1.x0() == 0.0);
    assert(r1.x1() == 0.0);
    assert(r1.y0() == 0.0);
    assert(r1.y1() == 0.0);

    assert(r2.x0() == 0.0);
    assert(r2.x1() == 1.0);
    assert(r2.y0() == 0.0);
    assert(r2.y1() == 1.0);

    assert(r3.x0() == 2.0);
    assert(r3.x1() == 4.0);
    assert(r3.y0() == 2.0);
    assert(r3.y1() == 4.0);

    // Aufgabe c) drei Tests für to_string()

    assert(to_string(r1).compare("[0.0:0.0, 0.0:0.0]"));
    assert(to_string(r2).compare("[0.0:1.0, 0.0:1.0]"));
    assert(to_string(r3).compare("[2.0:4.0, 2.0:4.0]"));

    // Aufgabe d) vier Tests für width() und height()

    assert(r2.width() == 1.0);
    assert(r3.width() == 2.0);

    assert(r2.height() == 1.0);
    assert(r3.height() == 2.0);

    // Aufgabe e) sechs Tests für is_valid() und area()
    assert(r1.is_valid() == true);
    assert(r2.is_valid() == true);
    assert(r4.is_valid() == false);

    assert(r1.area() == 0.0);
    assert(r2.area() == 1.0);
    assert(r4.area() == -1.0);

    // Aufgabe f) vier Tests für transpose() und translate()
    assert(r1.transpose() == Rectangle(Point(0.0, 0.0), Point(0.0, 0.0)));
    assert(r2.transpose() == Rectangle(Point(0.0, 0.0), Point(1.0, 1.0)));
    assert(r3.transpose() == Rectangle(Point(2.0, 2.0), Point(4.0, 4.0)));

    assert(r1.translate(Point(2.0, 2.0)) == Rectangle(Point(2.0, 2.0), Point(2.0, 2.0)));
    assert(r2.translate(Point(1.0, 1.0)) == Rectangle(Point(1.0, 1.0), Point(2.0, 2.0)));
    assert(r3.translate(Point(0.0, 0.0)) == Rectangle(Point(2.0, 2.0), Point(4.0, 4.0)));

    // Aufgabe g) sechs Tests für contains(Point) und contains(Rectangle)
    assert(r1.contains(Point(0.0, 0.0)));
    assert(r2.contains(Point(0.0, 0.0)));
    assert(!r3.contains(Point(-1.0, -1.0)));

    assert(r2.contains(r1));
    assert(!r3.contains(r2));
    assert(!r4.contains(r3));

    // Aufgabe h) vier Test für rectangle_union
    assert(rectangle_union(r1, r2) == Rectangle(Point(0.0, 0.0), Point(1.0, 1.0)));
    assert(rectangle_union(r2, r2) == Rectangle(Point(0.0, 0.0), Point(1.0, 1.0)));
    assert(rectangle_union(r2, r3) == Rectangle(Point(0.0, 0.0), Point(4.0, 4.0)));
    assert(rectangle_union(r2, r3) != Rectangle(Point(-1.0, -1.0), Point(4.0, 4.0)));

    // Aufgabe h) vier Test für rectangle_intersection
    assert(rectangle_intersection(r1, r2) == Rectangle(Point(0.0, 0.0), Point(0.0, 0.0)));
    assert(rectangle_intersection(r2, r2) == Rectangle(Point(0.0, 0.0), Point(1.0, 1.0)));
    assert(rectangle_intersection(r1, r1) == Rectangle(Point(0.0, 0.0), Point(0.0, 0.0)));
    assert(rectangle_intersection(r1, r2) == Rectangle(Point(0.0, 0.0), Point(0.0, 0.0)));

    std::cout << "alle Rectangle-Tests erfolgreich\n";
}

int main()
{
    testRectangle();
}
