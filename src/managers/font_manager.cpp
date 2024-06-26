#include <iostream>

#include "managers/font_manager.hpp"

FontManager::FontManager()
{
    ;
}

FontManager::~FontManager()
{
    for (auto a : table)
        if (a.second != nullptr)
        {
            TTF_CloseFont(a.second);
            a.second = nullptr;
        }
    table.clear();
}

FontManager* FontManager::getInstance()
{
    static FontManager* instance = new FontManager;
    return instance;
}

TTF_Font* FontManager::getFont(std::string key)
{
    auto a = table.find(key);
    if (a == table.end())
    {
        TTF_Font* font = TTF_OpenFont(key.c_str(), 28);
        if (font == nullptr)
        {
            std::cerr << "Could not open font " << key << '\n';
            std::cerr << "Error: " << TTF_GetError() << '\n';
            return nullptr;
        }
        table[key] = font;
    }
    return table[key];
}
