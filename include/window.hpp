#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL2/SDL.h>

#include "states/title_state.hpp"
#include "states/mario_state.hpp"
#include "states/text_state.hpp"
#include "states/animated_state.hpp"
#include "states/select_state.hpp"
#include "states/mm_fp_state.hpp"

enum CurrState
{
    TITLE,
    MARIO,
    TEXT,
    ANIMATED,
    SELECT,
    MM_FP
};

class Window
{
public:
    Window();
    ~Window();
    bool init(std::string, int, int);
    void close();
    void render();
    void handleEvent(SDL_Event&);
private:
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TitleState* title_state;
    MarioState* mario_state;
    TextState* text_state;
    AnimatedState* animated_state;
    SelectState* select_state;
    MMFPState* mm_fp_state;
    CurrState curr_state;
};

#endif
