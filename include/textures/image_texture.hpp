#ifndef IMAGE_TEXTURE_HPP
#define IMAGE_TEXTURE_HPP

#include <string>

#include "base_texture.hpp"

class ImageTexture : public BaseTexture
{
public:
    bool loadFromFile(std::string, SDL_Renderer*);
};
#endif
