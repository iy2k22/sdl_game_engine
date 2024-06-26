#include <iostream>

#include "textures/text_texture.hpp"
#include "managers/font_manager.hpp"

TextTexture::TextTexture()
{
    font = nullptr;
}

TextTexture::~TextTexture()
{
    if (font != nullptr)
    {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

bool TextTexture::openFont(std::string path)
{
    font = FontManager::getInstance()->getFont(path);
    return font != nullptr;
}

bool TextTexture::loadFromText(std::string text, SDL_Color& col, SDL_Renderer* renderer)
{
    surface = TTF_RenderText_Solid(font, text.c_str(), col);
    if (surface == nullptr)
    {
        std::cerr << "Couldn't load text!\n";
        std::cerr << "Error: " << TTF_GetError() << '\n';
        return false;
    }
    return createTexture(renderer);
}
