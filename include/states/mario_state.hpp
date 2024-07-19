#ifndef MARIO_STATE_HPP
#define MARIO_STATE_HPP

#include "base_state.hpp"
#include "../textures/image_texture.hpp"

class MarioState : public BaseState
{
public:
    MarioState();
    ~MarioState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
private:
    ImageTexture mario;
};
#endif
