
// here is my sdl2 saved:
// /usr/local/Cellar/sdl2/2.0.5/lib
// /usr/local/Cellar/sdl2/2.0.5/include
// compile: g++ Main.cpp -o Main -I/home/user/SDL/include/SDL2

/*
Works so far:
g++ SDLbasics.cpp -o sdl -I/usr/local/Cellar/sdl2/2.0.5/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2
*/


#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "Screen.h"
using namespace std;

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "SDL_init failed." << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        SDL_Quit();
        printf("Could not create window: %s\n", SDL_GetError());
        return 2;
    }

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(renderer == NULL)
    {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if(texture == NULL)
    {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    Uint32 * buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    // make window white by setting all bytes in buffer to maximum value (255 = 0xFF)
    // if value is 0, then screen is black.
    memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    // set individual pixel to white
    buffer[333333] = 0xFFFFFFFF; // two f's for each red, green, blue, alpha

    // set whole screen to certain color by looping over pixels:
    for(int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; ++i)
    {
        buffer[i] = 0xFFFF00FF;
    }

    // Drawing Code:
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while(!quit)
    {
        // Update particles
        // Draw particles
        // Check for messages/events

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    delete[] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);

    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
