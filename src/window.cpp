#include <iostream>

#include "window.hpp"
#include "states/select_state.hpp"

Window::Window()
{
    window = nullptr;
    renderer = nullptr;
    title_state = nullptr;
    mario_state = nullptr;
    text_state = nullptr;
    animated_state = nullptr;
    select_state = nullptr;
    curr_state = TITLE;
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
    title_state = new TitleState;
    return title_state->init(&width, &height, renderer);
}

void Window::close()
{
    if (title_state != nullptr)
    {
        title_state->close();
        title_state = nullptr;
    }
    if (text_state != nullptr)
    {
        text_state->close();
        text_state = nullptr;
    }
    if (mario_state != nullptr)
    {
        mario_state->close();
        mario_state = nullptr;
    }
    if (animated_state != nullptr)
    {
        animated_state->close();
        animated_state = nullptr;
    }
    if (select_state != nullptr)
    {
        select_state->close();
        select_state = nullptr;
    }
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
    switch (curr_state)
    {
        case TITLE:
            title_state->render();
            break;
        case MARIO:
            mario_state->render();
            break;
        case TEXT:
            text_state->render();
            break;
        case ANIMATED:
            animated_state->render();
            break;
        case SELECT:
            select_state->render();
            break;
    }
    SDL_RenderPresent(renderer);
}

void Window::handleEvent(SDL_Event& e)
{
    if (curr_state == TITLE)
    {
            int titleReturn = title_state->handleEvent(e);
            switch (titleReturn)
            {
                case MARIO:
                case TEXT:
                case ANIMATED:
                case SELECT:
                    title_state->close();
                    title_state = nullptr;
                    switch (titleReturn)
                    {
                        case MARIO:
                            mario_state = new MarioState;
                            mario_state->init(&width, &height, renderer);
                            curr_state = MARIO;
                            break;
                        case TEXT:
                            text_state = new TextState;
                            text_state->init(&width, &height, renderer);
                            curr_state = TEXT;
                            break;
                        case ANIMATED:
                            animated_state = new AnimatedState;
                            animated_state->init(&width, &height, renderer);
                            curr_state = ANIMATED;
                            break;
                        case SELECT:
                            select_state = new SelectState;
                            select_state->init(&width, &height, renderer);
                            curr_state = SELECT;
                            break;
                    }
                    break;
            }
    }
    else if (curr_state == SELECT)
    {
        if (!select_state->handleEvent(e))
            close();
    }
}
