// Exercise 10.2: Image class

#include "image.hpp"
#include <iostream>
#include <cassert>


Image chessboard(unsigned int width, unsigned int height, unsigned int square_size);
Image invert_image(Image const & image);

int main()
{
  try{
    Image im(4,3);
    assert(im.width() == 4);
    assert(im.height() == 3);
    assert(im.size() == 12);

    std::cout << to_string(im);
    for(int y = 0, h=im.height(); y<h; ++y)
    {
        for(int x = 0, w=im.width(); x < w; ++x)
        {
            assert(im(x,y) == 0);
        }
    }
    assert(to_string(im) == "0 0 0 0\n0 0 0 0\n0 0 0 0\n");


    // Fill picture with chessboard pattern
    for(int y = 0, h = im.height(); y < h; ++y)
    {
        for(int x = 0, w = im.width(); x < w; ++x)
        {
            if((x+y) % 2 != 0)
                im(x,y) = 255;
        }
    }
    // Test for desired output
    assert(to_string(im) == "0 255 0 255\n255 0 255 0\n0 255 0 255\n");

    // Print output on terminal and write to file
    std::cout << to_string(im);
    writePGM(im, "board4x3.pgm");

    // Read output in as image2 and check if the same as image1
    Image im2 = readPGM("board4x3.pgm");
    assert(im2.width()==4);
    assert(im2.height()==3);
    assert(im2.size()==12);

    for(int y = 0, h = im.height(); y < h; ++y)
    {
        for(int x = 0, w = im.width(); x < w; ++x)
        {
            assert(im(x,y) == im2(x,y));
        }
    }

    // Test if chessboard(4,3,1) is same as image1
    assert(im == chessboard(4,3,1));

    Image board = chessboard(400,300,20);
    writePGM(board, "chessboard400x300.pgm");
    Image board2 = readPGM("chessboard400x300.pgm");
    assert(board == board2);

    Image board3 = invert_image(board);
    writePGM(board3, "chessboard400x300_inverted.pgm");

    // Read picture and save it inverted
    Image lena = readPGM("lena.pgm");
    writePGM(invert_image(lena), "lena-inverted.pgm");
    return 0;
  }
  catch(std::exception & e)
  {
      std::cerr << e.what() << std::endl;
      return 1;
  }
}

Image chessboard(unsigned int width, unsigned int height, unsigned int square_size)
{
    Image board(width, height);
    for(int y = 0, h = board.height(); y < h; ++y)
    {
        for(int x = 0, w = board.width(); x < w; ++x)
        {
            if((x/square_size + y/square_size) % 2 != 0)
                board(x,y) = 255;
        }
    }
    return board;
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
