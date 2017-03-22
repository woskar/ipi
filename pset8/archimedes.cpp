//Problem 8.3: Use the algorithm of archimedes for calculation of pi

#include <iostream>
#include <iomanip>
#include <cmath>

void archimedes_float(bool set_formula_two);
void archimedes_double(bool set_formula_two);

int main()
{
    //archimedes_float(false);
    archimedes_double(true);
}

void archimedes_float(bool set_formula_two)
{
    //create two lambda expressions for calculation of 2n-sidelength

    if(set_formula_two) //this one is numerically better
    {
        auto s2n = [](float sn){return sn/(sqrt(2.0+sqrt(4.0-pow(sn,2.0))));};
        auto t2n = [](float tn){return (2.0*tn)/(sqrt(4.0+pow(tn,2.0))+2.0);};

        //set initial values: square in unit-circle, square outside
        float n = 4; //number of sides of the polygon
        float s = sqrt(2); //sidelength inner square
        float t = 2; //sidelength outer square

        for(int i=0; i<14; ++i)
        {
            std::cout << i << " " << n << "-Eck" << std::endl << std::setprecision(16) << (n/2.0 * s) << std::endl << (n/2 * t) << std::endl << M_PI << std::endl << std::endl;
            s = s2n(s);
            t = t2n(t);
            n = 2*n;
        }

    }
    else //formula one
    {
        auto s2n = [](float sn){return sqrt(2.0-sqrt(4.0-pow(sn,2.0)));};
        auto t2n = [](float tn){return (2.0/tn)*(sqrt(4.0+pow(tn,2.0))-2.0);};

        //set initial values: square in unit-circle, square outside
        float n = 4; //number of sides of the polygon
        float s = sqrt(2); //sidelength inner square
        float t = 2; //sidelength outer square

        for(int i=0; i<14; ++i)
        {
            std::cout << i << " " << n << "-Eck" << std::endl << std::setprecision(16) << (n/2.0 * s) << std::endl << (n/2 * t) << std::endl << M_PI << std::endl << std::endl;
            s = s2n(s);
            t = t2n(t);
            n = 2*n;
        }
    }
}

void archimedes_double(bool set_formula_two)
{
    //create two lambda expressions for calculation of 2n-sidelength

    if(set_formula_two) //this one is numerically better
    {
        auto s2n = [](double sn){return sn/(sqrt(2.0+sqrt(4.0-pow(sn,2.0))));};
        auto t2n = [](double tn){return (2.0*tn)/(sqrt(4.0+pow(tn,2.0))+2.0);};

        //set initial values: square in unit-circle, square outside
        double n = 4; //number of sides of the polygon
        double s = sqrt(2); //sidelength inner square
        double t = 2; //sidelength outer square

        for(int i=0; i<14; ++i)
        {
            std::cout << i << " " << n << "-Eck" << std::endl << std::setprecision(16) << (n/2.0 * s) << std::endl << (n/2 * t) << std::endl << M_PI << std::endl << std::endl;
            s = s2n(s);
            t = t2n(t);
            n = 2*n;
        }
    }
    else //formula one
    {
        auto s2n = [](double sn){return sqrt(2.0-sqrt(4.0-pow(sn,2.0)));};
        auto t2n = [](double tn){return (2.0/tn)*(sqrt(4.0+pow(tn,2.0))-2.0);};

        //set initial values: square in unit-circle, square outside
        double n = 4; //number of sides of the polygon
        double s = sqrt(2); //sidelength inner square
        double t = 2; //sidelength outer square

        for(int i=0; i<14; ++i)
        {
            std::cout << i << " " << n << "-Eck" << std::endl << std::setprecision(16) << (n/2.0 * s) << std::endl << (n/2 * t) << std::endl << M_PI << std::endl << std::endl;
            s = s2n(s);
            t = t2n(t);
            n = 2*n;
        }
    }
}
