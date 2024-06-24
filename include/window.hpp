#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL2/SDL.h>

#include "states/mario_state.hpp"

class Window
{
public:
    Window();
    ~Window();
    bool init(std::string, int, int);
    void close();
    void render();
private:
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    MarioState state;
};

#endif
