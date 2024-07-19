#include <SDL2/SDL_mixer.h>
#include <format>
#include <iostream>

#include "states/title_state.hpp"
#include "states/colors.hpp"

std::string TitleState::state_names[] = {
    "mario",
    "text",
    "animated",
    "select"
};

TitleState::TitleState()
{
    bgm = nullptr;
}

TitleState::~TitleState()
{
    close();
}

bool TitleState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h, r);
    if (!title_text.openFont("./assets/font.ttf") || !title_text.loadFromText("title", black, renderer))
        return false;
    for (int i = 0; i < NUM_STATES; ++i)
    {
        state_text.push_back(new TextTexture);
        if (!state_text[i]->openFont("./assets/font.ttf"))
            return false;
        std::string pressText = std::format("Press {} for {} state", i + 1, state_names[i]);
        if (!state_text[i]->loadFromText(pressText, black, renderer))
            return false;
    }
    bgm = Mix_LoadMUS("./assets/mario_be_playin.opus");
    if (bgm == nullptr)
    {
        std::cerr << "Couldn't load background music!\n";
        std::cerr << "Error: " << Mix_GetError() << '\n';
        return false;
    }
    return true;
}

void TitleState::close()
{
    if (Mix_PlayingMusic())
        Mix_HaltMusic();
    if (bgm != nullptr)
    {
        Mix_FreeMusic(bgm);
        bgm = nullptr;
    }
    for (auto a : state_text)
        if (a != nullptr)
        {
            a->free();
            a = nullptr;
        }
    state_text.clear();
    title_text.free();
}

void TitleState::render()
{
    title_text.render(renderer, (*width - title_text.getWidth()) / 2, 0);
    static int startPoint = (*height - (state_text[0]->getHeight() * state_text.size())) / 2;
    for (int i = 0; i < NUM_STATES; ++i)
    {
        state_text[i]->render(renderer, (*width - state_text[i]->getWidth()) / 2, startPoint + (state_text[i]->getHeight() * i));
    }
    if (!Mix_PlayingMusic())
        Mix_PlayMusic(bgm, -1);
}

int TitleState::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
        switch (e.key.keysym.sym)
        {
            case SDLK_1:
            case SDLK_2:
            case SDLK_3:
            case SDLK_4:
                return e.key.keysym.sym - SDLK_0;
        }
    return 0;
}
