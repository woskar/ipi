// Exercise 12.1: Transformation between Koordinate Systems

#include "image.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

double sq(double x)
{
    return x*x;
}

int main()
{
        const int w = 640; // set width of pictures
        const int h = 480; // set height of pictures

        int center_x = w/2; // center pixel width
        int center_y = h/2; // center pixel height

        double pixel_size1 = 1.0/64.0;
        double pixel_size2 = 1.0;

        Image image1(w, h);

        for(int y = 0; y < h; ++y)
        {
            for(int x = 0; x < w; ++x)
            {
                double xx = (x - center_x) * pixel_size1;
                double yy = (y - center_y) * pixel_size1;
                image1(x,y) = std::floor(255*sq(std::sin(sq(xx)+sq(yy))));
            }
        }

        Image image2(w, h);

        for(int y = 0; y < h; ++y)
        {
            for(int x = 0; x < w; ++x)
            {
                double xx = (x - center_x) * pixel_size2;
                double yy = (y - center_y) * pixel_size2;
                image2(x,y) = std::floor(255*sq(std::sin((sq(xx)+sq(yy))/4096)));
            }
        }

        //writePGM(image1, "image1.pgm");
        //writePGM(image2, "image2.pgm");

        // Test if both pictures are the same:
        assert(image1 == image2);
        std::cout << "The images match!\n";

        return 0;
}
