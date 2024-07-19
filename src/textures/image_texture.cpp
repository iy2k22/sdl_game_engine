#include "textures/image_texture.hpp"
#include "managers/image_manager.hpp"

bool ImageTexture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
    surface = ImageManager::getInstance()->getImage(path);
    if (surface == nullptr)
        return false;
    return createTexture(renderer);
}
