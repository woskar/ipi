// Exercise 12.2: Visualization of Mandelbrot Fractal

#include "image.hpp"
#include <iostream>
#include <cassert>
#include <complex>
#include <cctype>

#define MAX_ITERATION 512

class FractalView
{
private:
    double x_center_;
    double y_center_;
    double pixel_size_;

public:

    // Constructor
    FractalView(double x, double y, double pixel)
    : x_center_(x)
    , y_center_(y)
    , pixel_size_(pixel)
    {}

private:
    int iterations_until_limit(std::complex<double> const& c) const
    {
        std::complex<double> z(0,0);
        int count = 0;
        //std::cout << "next number" << std::endl;
        while(true)
        {
            z = z*z + c;
            count++;
            //std::cout << std::norm(z) << " " << c << std::endl;
            if(count >= MAX_ITERATION)
                break;
            if(std::norm(z) >= 1000)
                break;
        }
        //std::cout << count << std::endl;
        return count;
    }

    std::complex<double> pixel_to_complex(Image const & img, int ix, int iy) const
    {

        double x = ((ix-(img.width()/2))*(*this).pixel_size_)-x_center_;
        double y = ((iy-(img.height()/2))*(*this).pixel_size_)-y_center_;
        std::complex<double> c(x,y);
        // std::cout << "Pixelsize: " << (*this).pixel_size_ << std::endl;
        // std::cout << c << std::endl;
        return c;
    }

    uint16_t color_scheme(int num_iterations) const
    {
        if(num_iterations >=  MAX_ITERATION)
            return 0;
        else
        {
            return int(255-std::sqrt(num_iterations)*11.2);
        }
    }

public:
    void render_mandelbrot(Image & img) const
    {
        for(int y=0, h=img.height(); y < h; ++y)
        {
            for(int x=0, w=img.width(); x < w; ++x)
            {
                img(x,y) = color_scheme(iterations_until_limit(pixel_to_complex(img, x, y)));
            }
        }
    }


};

char process_user_input(){
    char input;
    bool input_valid = false;
    while(!input_valid)
    {
        try
        {
            std::cin >> input;
            if(input == 'w'|| input == 'a'|| input == 's'|| input == 'd'|| input == '+'|| input == '-'|| input == 'b'||input==' ')
                input_valid = true;
            else
                std::cout << "\nVersuche es nochmal mit\nw: hoch\na: links\ns: runter\nd: rechts\n+: zoom rein\n-: zoom raus\nb: beenden\n";
        }
        catch(std::exception & e)
        {
            std::cerr << "Ungültige Eingabe: " << e.what() << "\nVersuche es nochmal mit\nw: hoch\na: links\ns: runter\nd: rechts\n+: zoom rein\n-: zoom raus\nb: beenden\n";
        }
    }
    return input;
}

int main()
{
    int width = 640;
    int height = 480;
    double pixel = 640.0;
    double x_center = 0.0;
    double y_center = 0.0;
    double zoom = 1;

    std::cout << "Herzlich Willkommen bei der Expedition Mandelbrot!";
    std::cout << "\nSo funktioniert die Steuerung:\nw: hoch\na: links\ns: runter\nd: rechts\n+: zoom rein\n-: zoom raus\nb: beenden\n\n";

    FractalView fractal(x_center, y_center, 4.0/pixel);
    Image image(width, height);
    fractal.render_mandelbrot(image);
    writePGM(image, "mandelbrot.pgm");

    while(true)
    {
        char c = process_user_input();
        if(c == 'b')
        {
            break;
        }

        if(c == '+')
            zoom *= 2.0;

        if(c == '-')
            zoom /= 2.0;

        if(c == 'a')
            x_center += (2.0/zoom);

        if(c == 'd')
            x_center -= (2.0/zoom);

        if(c == 's')
            y_center -= (2.0/zoom);

        if(c == 'w')
            y_center += (2.0/zoom);


        std::cout << "x_center: " << x_center << std::endl;
        std::cout << "y_center: " << y_center << std::endl;
        std::cout << "zoom: " << zoom << std::endl;
        std::cout << "pixelsize: " << 4.0/(pixel*zoom) << std::endl << std::endl;

        FractalView fractal(x_center, y_center, 4.0/(pixel*zoom));
        Image image(width, height);
        fractal.render_mandelbrot(image);
        writePGM(image, "mandelbrot.pgm");
    }

    return 0;
}

/*
+
x_center: 0.0282593
y_center: 0.75
zoom: 1.04858e+06
pixelsize: 5.96046e-09

d
x_center: 0.0282592
y_center: 0.75
zoom: 6.87195e+10
pixelsize: 9.09495e-14

*/
