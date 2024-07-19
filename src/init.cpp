#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "init.hpp"

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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
    if (TTF_Init() == -1)
    {
        std::cerr << "Could not init SDL_ttf!\n";
        std::cerr << "Error: " << TTF_GetError() << '\n';
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "Could not init SDL_mixer!\n";
        std::cerr << "Error: " << Mix_GetError() << '\n';
        return false;
    }
    return true;
}

void close()
{
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
