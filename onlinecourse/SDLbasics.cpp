// run with:
// g++ SDLbasics.cpp -o sdl -I/usr/local/Cellar/sdl2/2.0.5/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
using namespace std;

int main()
{

    // create a Screen object
    Screen screen;

    if(screen.init() == false)
        cout << "Error initializing SDL." << endl;



    while(true)
    {
        // Update particles

        // Draw particles
        for(int y=0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        screen.setPixel(400, 300, 255, 255, 255);

        screen.setPixel(200, 300, 255, 255, 255);

        // Draw the screen
        screen.update();

        // Check for messages/events
        if(screen.processEvents() == false)
            break;
    }

    screen.close();
    return 0;


}
