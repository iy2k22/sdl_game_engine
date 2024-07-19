#ifndef ANIMATED_STATE_HPP
#define ANIMATED_STATE_HPP

#include <vector>

#include "base_state.hpp"

#include "../textures/image_texture.hpp"

const int NUM_FRAMES = 3;

class AnimatedState : public BaseState
{
public:
    AnimatedState();
    ~AnimatedState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
private:
    ImageTexture nes_mario;
    std::vector<SDL_Rect> running_anim;
};

#endif
