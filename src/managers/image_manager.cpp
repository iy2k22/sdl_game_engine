#include <iostream>

#include <SDL2/SDL_image.h>

#include "managers/image_manager.hpp"

ImageManager::ImageManager()
{
    ;
}

ImageManager::~ImageManager()
{
    for (auto a : table)
        if (a.second != nullptr)
        {
            SDL_FreeSurface(a.second);
            a.second = nullptr;
        }
    table.clear();
}

ImageManager* ImageManager::getInstance()
{
    static ImageManager* instance = new ImageManager;
    return instance;
}

SDL_Surface* ImageManager::getImage(std::string path)
{
    auto a = table.find(path);
    if (a == table.end())
    {
        SDL_Surface* img = IMG_Load(path.c_str());
        if (img == nullptr)
        {
            std::cerr << "Could not open image " << path << '\n';
            std::cerr << "Error: " << IMG_GetError() << '\n';
            return nullptr;
        }
        table[path] = img;
    }
    return table[path];
}
