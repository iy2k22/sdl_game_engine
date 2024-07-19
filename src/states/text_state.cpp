#include "states/text_state.hpp"
#include "states/colors.hpp"

TextState::~TextState()
{
    close();
}

bool TextState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h, r);
    return mario_text.openFont("./assets/font.ttf") && mario_text.loadFromText("mario", black, renderer);
}

void TextState::close()
{
    mario_text.free();
    BaseState::close();
}

void TextState::render()
{
    mario_text.render(renderer, (*width - mario_text.getWidth()) / 2, (*height - mario_text.getHeight()) / 2);
}
