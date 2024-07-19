#ifndef BASE_STATE_HPP
#define BASE_STATE_HPP

#include <SDL2/SDL.h>

class BaseState
{
public:
    BaseState();
    ~BaseState();
    void init(int*, int*, SDL_Renderer*);
    void close();
protected:
    SDL_Renderer* renderer;
    int* width;
    int* height;
};

#endif
