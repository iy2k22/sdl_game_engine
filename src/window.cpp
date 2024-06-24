#include <iostream>

#include "window.hpp"

Window::Window()
{
    window = nullptr;
    renderer = nullptr;
    width = height = 0;
}

Window::~Window()
{
    close();
}

bool Window::init(std::string title, int w, int h)
{
    width = w;
    height = h;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Could not create window!\n";
        std::cerr << "Error: " << SDL_GetError() << '\n';
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cerr << "Could not create renderer!\n";
        std::cerr << "Error: " << SDL_GetError() << '\n';
        return false;
    }
    return state.init(&width, &height, renderer);
}

void Window::close()
{
    state.close();
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    width = height = 0;
}

void Window::render()
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    state.render();
    SDL_RenderPresent(renderer);
}
