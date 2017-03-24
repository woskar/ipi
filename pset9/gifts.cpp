// Problem 9.2: Gifts
// Goal of this exercise is to develop an algorithm for optimal placement of gifts unter the christmas tree.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

//including the solution for 9.1: Definition of class Rectangle
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
        if((*this).height() == 0 && (*this).width() == 0)
            return 0.0;
        else if(!(*this).is_valid())
            return -1.0;
        else
            return (*this).height() * (*this).width();
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

// Here starts Exercise 9.2:

// Calculates BSSF-Score, "how favorable is it to place obj in free space?"
double bssf_score(Rectangle const& free, Rectangle const& obj)
{

    double res = std::min((free.width()-obj.width()),(free.height()-obj.height()));
    double big_number = 1e300;

    if(res < 0) //the object does not fit in free space
        return big_number;
    else
        return res;
}

struct Combination
{
    double score;
    int free_index;
    int to_be_placed_index;
    bool transpose;

    Combination()
    :score(0)
    ,free_index(0)
    ,to_be_placed_index(0)
    ,transpose(false)
    {}

};

std::vector<Combination> combinations(std::vector<Rectangle> const & free_rectangles, std::vector<Rectangle> const & to_be_placed)
{
    std::vector<Combination> combinations;
    int combi_count = 0;
    for(int i=0, n=free_rectangles.size(); i<n; ++i)
    {
        for(int j=0, m=to_be_placed.size(); j<m; ++j)
        {
            combinations.push_back(Combination());

            combinations[combi_count].score =  bssf_score(free_rectangles[i], to_be_placed[j]);
            combinations[combi_count].free_index = i;
            combinations[combi_count].to_be_placed_index = j;
            combinations[combi_count].transpose = false;

            combi_count++;

            combinations.push_back(Combination());

            combinations[combi_count].score =  bssf_score(free_rectangles[i], to_be_placed[j].transpose());
            combinations[combi_count].free_index = i;
            combinations[combi_count].to_be_placed_index = j;
            combinations[combi_count].transpose = true;

            combi_count++;
        }
    }
    return combinations;
}

int main()
{
    Rectangle table(Point(100.0, 80.0));
    Rectangle tree_stand(Point(30.0, 30.0));

    std::vector<Rectangle> gifts =
    {
        Rectangle(Point(20.0, 10.0)),
        Rectangle(Point(10.0, 11.0)),
        Rectangle(Point(3.0, 46.0)),
        Rectangle(Point(3.0, 4.0)),
        Rectangle(Point(6.0, 16.0)),
        Rectangle(Point(10.0, 20.0)),
        Rectangle(Point(20.0, 8.0)),
        Rectangle(Point(12.0, 37.0)),
        Rectangle(Point(11.0, 15.0)),
        Rectangle(Point(40.0, 63.0)),
        Rectangle(Point(23.0, 6.0)),
        Rectangle(Point(16.0, 12.0)),
        Rectangle(Point(25.0, 20.0)),
        Rectangle(Point(67.0, 3.0)),
        Rectangle(Point(31.0, 29.0)),
        Rectangle(Point(12.0, 11.0)),
        Rectangle(Point(8.0, 9.0)),
        Rectangle(Point(3.0, 8.0)),
        Rectangle(Point(21.0, 13.0)),
        Rectangle(Point(46.0, 13.0)),
        Rectangle(Point(11.0, 75.0)),
        Rectangle(Point(4.0, 3.0)),
        Rectangle(Point(19.0, 7.0)),
        Rectangle(Point(33.0, 7.0)),
        Rectangle(Point(6.0, 16.0)),
        Rectangle(Point(21.0, 4.0)),
        Rectangle(Point(8.0, 8.0)),
        Rectangle(Point(3.0, 86.0)),
        Rectangle(Point(20.0, 6.0)),
        Rectangle(Point(21.0, 3.0)),
        Rectangle(Point(13.0, 59.0)),
        Rectangle(Point(4.0, 20.0))
    };

    std::vector<Rectangle> to_be_placed;
    std::vector<Rectangle> already_placed;
    std::vector<Rectangle> free_rectangles;

    // Initialize the Vectors:
    free_rectangles.push_back(table);
    to_be_placed.push_back(tree_stand);

    for(int i=0, n=gifts.size(); i<n; ++i)
    {

        to_be_placed.push_back(gifts[i]);
    }




 for(int i=0, n=to_be_placed.size(); i<n; ++i)
 {
    std::cout << "Size of to_be_placed gifts vector is " << n << " in iteration " << i << std::endl;
    // Create a vector with different combinations and score
    std::vector<Combination> combis = combinations(free_rectangles, to_be_placed);
    // Sort the combinations with lambda expression, to have best score on first position
    std::sort(combis.begin(), combis.end(), [](Combination a, Combination b){return a.score < b.score;});

    std::cout << "Best score is " << combis[0].score << ", next would be " << combis[1].score << std::endl;

    // only if obj can be placed continue with:
    if(combis[0].score < 1e300)
    {
        // Set indices of the best fitting object:
        int best_free = combis[0].free_index;
        int best_obj = combis[0].to_be_placed_index;
        // copy the desired Rectangle
        Rectangle new_rect = to_be_placed[best_obj];

        std::cout << "The new Rectangle is " <<to_string(new_rect) << std::endl;

        // transpose it when algorithm said so
        if(combis[0].transpose)
            new_rect.transpose();
        // translate the new rectangle to have lower left corner on top of free space
        new_rect.translate(Point(free_rectangles[best_free].p0().x() - to_be_placed[best_obj].p0().x(),
                                 free_rectangles[best_free].p0().y() - to_be_placed[best_obj].p0().y()));
        // insert new_rect into already_placed
        already_placed.push_back(new_rect);

        std::cout << "Size of already placed is now " << already_placed.size() << std::endl;

        // Create new free spaces from the uncovered space, push back on free spaces
        // if width free < height free: create horizontal cut
        if(free_rectangles[best_free].width() < free_rectangles[best_free].height())
        {
            free_rectangles.push_back(Rectangle(Point(to_be_placed[best_obj].p0().x(), to_be_placed[best_obj].p1().y()),
                                                     free_rectangles[best_free].p1()
                                                     ));
            free_rectangles.push_back(Rectangle(Point(to_be_placed[best_obj].p1().x(), to_be_placed[best_obj].p0().y()),
                                                     Point(free_rectangles[best_free].p1().x(), to_be_placed[best_obj].p1().y())
                                                     ));
        }

        // else create vertical cut
        else
        {
            free_rectangles.push_back(Rectangle(Point(to_be_placed[best_obj].p0().x(), to_be_placed[best_obj].p1().y()),
                                                     Point(to_be_placed[best_obj].p1().x(), free_rectangles[best_free].p1().y())
                                                     ));
            free_rectangles.push_back(Rectangle(Point(to_be_placed[best_obj].p1().x(), to_be_placed[best_obj].p0().y()),
                                                     free_rectangles[best_free].p1()
                                                     ));
        }

         // Remove best_obj from to_be_placed;
         to_be_placed.erase(to_be_placed.begin()+best_obj);

        // Remove taken free space from free_rectangles
        free_rectangles.erase(free_rectangles.begin()+best_free);
    }

 }
 std::cout << "The placing magic has been done.\n \nTo be placed gifts:\n";
 for(int i=0, n=to_be_placed.size(); i<n; ++i)
 {
     std::cout << to_string(to_be_placed[i]) << std::endl;
 }

 std::cout << "Now the table looks like this with already placed gifts:\n";
 std::cout << "Size of already placed is now " << already_placed.size() << std::endl;

 for(int i=0, n=already_placed.size(); i<n; ++i)
 {
     std::cout << to_string(already_placed[i]) << std::endl;
 }

    return 0;
}
