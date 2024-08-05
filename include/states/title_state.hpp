#ifndef TITLE_STATE_HPP
#define TITLE_STATE_HPP

#include <string>
#include <vector>

#include <SDL2/SDL_mixer.h>

#include "base_state.hpp"
#include "../textures/text_texture.hpp"

const int NUM_STATES = 5;

class TitleState : public BaseState
{
public:
    TitleState();
    ~TitleState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
    int handleEvent(SDL_Event&);
private:
    TextTexture title_text;
    static std::string state_names[NUM_STATES];
    std::vector<TextTexture*> state_text;
    Mix_Music* bgm;
};

#endif
