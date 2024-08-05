#ifndef BASE_TEXTURE_HPP
#define BASE_TEXTURE_HPP

#include <SDL2/SDL.h>

class BaseTexture
{
public:
    BaseTexture();
    ~BaseTexture();
    void free();
    void render(SDL_Renderer*, int, int, SDL_Rect* = nullptr);
    bool createTexture(SDL_Renderer*);
    int getWidth();
    int getHeight();
    void setRGBA(Uint8, Uint8, Uint8);
    void setWidth(int);
    void setHeight(int);
    void scale(float);
protected:
    SDL_Surface* surface;
    SDL_Texture* texture;
    int width;
    int height;
};

#endif
