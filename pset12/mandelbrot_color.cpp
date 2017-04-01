// Exercise 12.2: Visualization of Mandelbrot Fractal

#include "image_rgb.hpp"
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
        std::complex<double> z(0.0,0.0);

        for(int i=0; i<MAX_ITERATION; ++i)
        {
            if (std::norm(z) >= 1000)
                return i;
            z = z*z + c;
        }
        return MAX_ITERATION;
    }

    template <typename PixelType>
    std::complex<double> pixel_to_complex(Image<PixelType> const & img, int ix, int iy) const
    {

        double x = ((ix-(img.width()/2))*(*this).pixel_size_)-x_center_;
        double y = ((iy-(img.height()/2))*(*this).pixel_size_)-y_center_;
        std::complex<double> c(x,y);
        // std::cout << "Pixelsize: " << (*this).pixel_size_ << std::endl;
        // std::cout << c << std::endl;
        return c;
    }

    RGBColor color_scheme(int num_iterations) const
    {
        if(num_iterations >=  MAX_ITERATION)
            return RGBColor();
        double n = std::pow(num_iterations, 1./5.);
        double m = std::pow(MAX_ITERATION, 1./5.);
        double H = 180. * std::sin(n*2. * M_PI / m+0.2) + 180.;
        double S = 1.0;
        double V = 0.3*std::sin(n*.5*M_PI/200.) + .7;

        return hsv_to_rgb(H,S,V);
    }

public:
    template <typename PixelType>
    void render_mandelbrot(Image<PixelType> & img) const
    {
        for(int y=0, h=img.height(); y < h; ++y)
        {
            for(int x=0, w=img.width(); x < w; ++x)
            {
                // Standard version for rendering
                //img(x,y) = color_scheme(iterations_until_limit(pixel_to_complex(img, x, y)));

                // Implementation of Anti-Aliasing
                int i1 = iterations_until_limit(pixel_to_complex(img, x+.25, y+0.25));
                int i2 = iterations_until_limit(pixel_to_complex(img, x-.25, y+0.25));
                int i3 = iterations_until_limit(pixel_to_complex(img, x+.25, y-0.25));
                int i4 = iterations_until_limit(pixel_to_complex(img, x-.25, y-0.25));
                // return mean of iterations
                int iterations = (i1 + i2 + i3 + i4) / 4;
                img(x, y) = color_scheme(iterations);
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
    unsigned int width = 640;
    unsigned int height = 480;
    double pixel = 640.0;
    double x_center = 0.0;
    double y_center = 0.0;
    double zoom = 1;

    std::cout << "Herzlich Willkommen bei der Expedition Mandelbrot!";
    std::cout << "\nSo funktioniert die Steuerung:\nw: hoch\na: links\ns: runter\nd: rechts\n+: zoom rein\n-: zoom raus\nb: beenden\n\n";

    FractalView fractal(x_center, y_center, 4.0/pixel);

    typedef RGBColor PixelType;
    Image<PixelType> image(width, height);
    fractal.render_mandelbrot(image);
    writePPM(image, "mandelbrot_color.pgm");

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
        Image<PixelType> image(width, height);
        fractal.render_mandelbrot(image);
        writePPM(image, "mandelbrot_color.pgm");
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
