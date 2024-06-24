#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "init.hpp"

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Could not init SDL!\n";
        std::cerr << "Error: " << SDL_GetError() << '\n';
        return false;
    }
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best"))
        std::cerr << "Warning: linear texture filtering not enabled!\n";
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cerr << "Could not init SDL_image!\n";
        std::cerr << "Error: " << IMG_GetError() << '\n';
        return false;
    }
    return true;
}

void close()
{
    IMG_Quit();
    SDL_Quit();
}
