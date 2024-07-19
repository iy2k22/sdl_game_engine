#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

#include <map>
#include <string>

#include <SDL2/SDL_ttf.h>

class FontManager
{
public:
    static FontManager* getInstance();
    TTF_Font* getFont(std::string);
private:
    FontManager();
    ~FontManager();
    std::map<std::string, TTF_Font*> table;
};

#endif
