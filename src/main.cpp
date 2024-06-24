#include <SDL2/SDL.h>

#include "init.hpp"
#include "window.hpp"

int main()
{
    Window window;
    if (init() && window.init("sdl", 640, 480))
    {
        bool quit = false;
        SDL_Event e;
        while (!quit)
        {
            while (SDL_PollEvent(&e))
                if (e.type == SDL_QUIT)
                    quit = true;
            window.render();
        }
        window.close();
    }
    close();
    return 0;
}
