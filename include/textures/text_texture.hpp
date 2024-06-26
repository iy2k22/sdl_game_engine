#ifndef TEXT_TEXTURE_HPP
#define TEXT_TEXTURE_HPP

#include <string>

#include <SDL2/SDL_ttf.h>

#include "base_texture.hpp"

class TextTexture : public BaseTexture
{
public:
    TextTexture();
    ~TextTexture();
    bool openFont(std::string);
    bool loadFromText(std::string, SDL_Color&, SDL_Renderer*);
private:
    TTF_Font* font;
};

#endif
