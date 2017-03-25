// Exercise 10.3: Kaleidoscope Image Manipulation

#include "image.hpp"
#include <cassert>
#include <iostream>

Image mirror_x(Image const & image);
Image mirror_y(Image const & image);
Image kaleidoscope4(Image const & image);
Image kaleidoscope8(Image const & image);
Image invert_image(Image const & image);

int main()
{
    try
    {
        // Read lena into the program
        Image lena = readPGM("lena.pgm");

        // Test mirror functions with test images
        Image mirror_x_test = readPGM("mirror_x_test.pgm");
        Image mirror_y_test = readPGM("mirror_y_test.pgm");
        assert(mirror_x(lena) == mirror_x_test);
        assert(mirror_y(lena) == mirror_y_test);

        // Test kaleidoscope functions:
        Image kaleidoskop4_test = readPGM("kaleidoskop4_test.pgm");
        assert(kaleidoscope4(lena) == kaleidoskop4_test);
        Image kaleidoskop8_test = readPGM("kaleidoskop8_test.pgm");
        assert(kaleidoscope8(lena) == kaleidoskop8_test);

        // Save final result :D
        writePGM(kaleidoscope8(kaleidoscope8(kaleidoskop8_test)), "kaleieiei.pgm");

    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

Image mirror_x(Image const & image)
{
    // Return a image twice the size
    Image result(image.width()*2, image.height());
    for(int y = 0, h=image.height(); y < h; ++y)
    {
        for(int x = 0, w=image.width(); x < w; ++x)
        {
            result(x,y) = image(x,y);
            result(result.width()-x-1, y) = image(x,y);
        }
    }
    return result;
}

Image mirror_y(Image const & image)
{
    // Return a image twice the size
    Image result(image.width(), image.height()*2);
    for(int y = 0, h=image.height(); y < h; ++y)
    {
        for(int x = 0, w=image.width(); x < w; ++x)
        {
            result(x,y) = image(x,y);
            result(x, result.height()-1-y) = image(x,y);
        }
    }
    return result;
}

Image kaleidoscope4(Image const & image)
{
    return mirror_y(mirror_x(image));
}

Image kaleidoscope8(Image const & image)
{
    // Lower left triangle is copied
    Image diagonal = image;
    // Upper left triangle overwritten
    for(int y = 0, h=image.height(); y < h; ++y)
    {
        for(int x = y, w=image.width(); x < w; ++x)
        {
            diagonal(x,y) = image(y,x);
        }
    }
    return kaleidoscope4(diagonal);
}

Image invert_image(Image const & image)
{
    Image result(image.width(), image.height());
    for(int y = 0, h = image.height(); y < h; ++y)
    {
        for(int x = 0, w = image.width(); x < w; ++x)
        {
                result(x,y) = 255 - image(x,y);
        }
    }
    return result;
}
