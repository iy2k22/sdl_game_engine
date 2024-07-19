#ifndef IMAGE_MANAGER_HPP
#define IMAGE_MANAGER_HPP

#include <map>
#include <string>

#include <SDL2/SDL.h>

class ImageManager
{
public:
    static ImageManager* getInstance();
    SDL_Surface* getImage(std::string path);
private:
    ImageManager();
    ~ImageManager();
    std::map<std::string, SDL_Surface*> table;
};

#endif
