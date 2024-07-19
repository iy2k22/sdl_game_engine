#ifndef TEXT_STATE_HPP
#define TEXT_STATE_HPP

#include "base_state.hpp"
#include "../textures/text_texture.hpp"

class TextState : public BaseState
{
public:
    ~TextState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
private:
    TextTexture mario_text;
};

#endif
