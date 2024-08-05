#include <iostream>

#include "textures/base_texture.hpp"

BaseTexture::BaseTexture()
{
    surface = nullptr;
    texture = nullptr;
    width = height = 0;
}

BaseTexture::~BaseTexture()
{
    free();
}

void BaseTexture::free()
{
    if (surface != nullptr)
        surface = nullptr;
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    width = height = 0;
}

void BaseTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {x, y, width, height};
    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

bool BaseTexture::createTexture(SDL_Renderer* renderer)
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr)
    {
        std::cerr << "Could not create texture!\n";
        std::cerr << "Error: " << SDL_GetError() << '\n';
        return false;
    }
    width = surface->w;
    height = surface->h;
    return true;
}

int BaseTexture::getHeight()
{
    return height;
}

int BaseTexture::getWidth()
{
    return width;
}

void BaseTexture::setRGBA(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(texture, r, g, b);
}

void BaseTexture::setWidth(int w)
{
    width = w;
}

void BaseTexture::setHeight(int h)
{
    height = h;
}

void BaseTexture::scale(float factor)
{
    height *= factor;
    width *= factor;
}
