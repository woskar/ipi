// Screen.h

#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Texture * m_texture;
    Uint32 * m_buffer;

public:
    // Constructor with initializer list
    Screen()
    : m_window(NULL)
    , m_renderer(NULL)
    , m_texture(NULL)
    , m_buffer(NULL)
    {}

    // True if init succeeds
    bool init()
    {
        return true;
    }

    // Eventprocessing
    bool processEvents()
    {
        return false;
    }

    // Deallocation/Close-down function
    void close();



};

#endif
