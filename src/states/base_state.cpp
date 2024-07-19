#include "states/base_state.hpp"

BaseState::BaseState()
{
    renderer = nullptr;
    width = height = nullptr;
}

BaseState::~BaseState()
{
    close();
}

void BaseState::init(int* w, int* h, SDL_Renderer* r)
{
    width = w;
    height = h;
    renderer = r;
}

void BaseState::close()
{
    if (renderer != nullptr)
        renderer = nullptr;
    if (width != nullptr)
        width = nullptr;
    if (height != nullptr)
        height = nullptr;
}
