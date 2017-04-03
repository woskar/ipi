Notes on C++
===========

Kapselung (encapsulation) = Trennung des Rumpfes einer Klassendefinition in zwei Teile:
* öffentlicher Teil (public): Schnittstelle (interface) für Zugriff durch Benutzer
* privater Teil (private): Mitglieder (member variables & methods) zur Implementierung der Schnittstelle

Vorteile:
- öffentliches Interface einfach
- änderung der Implementierung bei gleichem Interface (Rückwärts-Kompatibilität)
- Benutzer kann nicht unbeabsichtigt Konsistenz verletzen
- komplexe Implementierungsdetails bleiben verborgen
- information hiding: Prinzip der versteckten information

Konstruktor = öffentliche Funktion zum Initialisieren des Speichers
- gleicher Name wie Klasse selbst
- kein Rückgabewert
- ohne Argument, dann Standardkonstruktor (default constructor)

Rule of three:
alle oder keine der folgenden Member-Funktionen einer Klasse implementieren:
- Destruktor
- Kopierkonstruktor
- Kopier-Zuweisung

Nur Funktionen mit Klassentyp als linkem Argument können Memberfunktion sein

Freie Funktionen: kommen nach der Klassendefinition, wie ganz normale andere Funktionen auch
können nur noch auf öffentliches Profil der Klasse zugreifen

Objekte nachträglich verändern: drei Möglichkeiten
- Setter Funktionen implementieren
- Index-zugriff mit Memberfunktion operator[] implementieren
- Zuweisungsoperator (copy assignment operator)


class Point
{
    // class is per default private (default von struct is public)

    // member variables:
    double x_; //enden nach Konvention mit _
    double y_;

    // member functions/methods:
public:
    // Standardkonstruktor ohne Argumente:
    Point() : x_(0.0) , y_(0.0) {} //kein Semikolon nach {} !

    // Konstruktor:
    Point(double x, double y) : x_(x), y_(y) {}

    // Destruktor: // wenn dieser Implementiert, dann beachte Rule of three
    ~Point(){}

    // Getter functions: erlauben den Zustand abzufragen

    double x() const        //const markiert explizit als read-only, verändert also Membervariablen nicht
    {
        return (*this).x_;
    }

    double y() const
    {
        return (*this).y_;
    }

    // Setter Funktionen um Membervariablen zu ändern

    void setX(double new_x)
    {
        x_ = new_x;
    }

    void setY(double new_y)
    {
        y_ = new_y;
    }

    // Index-zugriff implementieren:

    double operator[](int index) const
    {
        if(index == 0) {return x_;}
        if(index == 1) {return y_;}
    }

    double operator[](int index)
    {
        if(index == 0) {return x_;}
        if(index == 1) {return y_;}
    }

    // Zuweisungsoperator = copy assignment operator

    void operator=(double v)
    {
        x_ = v;
        y_ = v;
    }

    operator=(Point const & other)
    {
        x_ = other.x_;
        y_ = other.y_;
    }

    // beachte hierbei:
    // argument ist eine konstante Refernez, denn Point other soll weder kopiert noch geändert werden
    // der assignment operator (operator=) gibt eine Referenz zurück, das erlaubt "operator chaining", d.h. Kettenzuweisung wie zum beispiel a = b = c = d = e = 42;

    Point & operator=(Point const & other)
    {
        // check for self-assignment (online, nicht aus VL):
        if (this == & other) // same object? (Adressen gleich, da this ist pointer zum called objekt, & other ist pointer zum Objekt das als Argument gegeben wird http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html)
            return *this;    // yes, so skip assignment and just return *this

        x_ = other.x_;
        y_ = other.y_;
        return (*this); // Rückgabe einer Referenz zum Objekt selbst (obwohl *this eine instance ist, konvertiert C++ diese impolizit in eine Refernz zur instance)
    }

    Point & operator+=(Point const & other)
    {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }




    // Gleichheits-Operatoren

    bool equals(Point other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    bool operator==(Point other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    bool operator!=(Point other) const
    {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // beispielhafte Member-funktionen: Transponieren und verschieben eines Punktes

    Point transpose() const
    {
       Point res((*this).y(), (*this).x());
       return res;
    }


    Point translate(Point const & v) const
    {
       Point res((*this).x() + v.x(), (*this).y() + v.y());
       return res;
    }

};

// freie Funktionen: außerhalb Klassendefinition, können nur auf öffenliches Interface der Klasse zugreifen

// Funktion zum umwandeln eines Punktes in einen String:
std::string to_string(Point const & p)
{
    std::string result;
    result += "[" + std::to_string((*this).x()) + " ," + std::to_string((*this).y()) + "]";
    return result;
}

Point operator+(Point p1, Point p2)
{
   return Point(p1.x() + p2.x(), p1.y() + p2.y());
}

Point operator-(Point p1, Point p2)
{
   return Point(p1.x() - p2.x(), p1.y() - p2.y());
}


Point operator*(Point p1, Point p2)
{
   return Point(p1.x() * p2.x(), p1.y() * p2.y());
}

Point operator/(Point p1, Point p2)
{
   return Point(p1.x() / p2.x(), p1.y() / p2.y());
}

Point operator*(double s, Point p)
{
   return Point(s * p.x(), s * p.y());
}

Point operator*(Point p, double s)
{
   return s*p;
}


Point operator/(Point p, double s)
{
   return Point(p.x()/s, p.y()/s);
}

Point operator-(Point p)
{
   return Point(-p.x(), -p.y());
}
