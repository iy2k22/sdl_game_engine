#include "states/mario_state.hpp"

MarioState::MarioState()
{
    ;
}

MarioState::~MarioState()
{
    close();
}

bool MarioState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h, r);
    return mario.loadFromFile("./assets/luigi.png", renderer);
}

void MarioState::close()
{
    mario.free();
    BaseState::close();
}

void MarioState::render()
{
    mario.render(renderer, (*width - mario.getWidth()) / 2, (*height - mario.getHeight()) / 2);
}
