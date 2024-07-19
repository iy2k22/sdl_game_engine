#ifndef SELECT_STATE_HPP
#define SELECT_STATE_HPP

#include <map>
#include <string>
#include <vector>

#include "base_state.hpp"
#include "../textures/text_texture.hpp"

const int NUM_WORLDS = 6;

enum CurrSelectState
{
    WORLD,
    LEVEL
};

class SelectState : public BaseState
{
public:
    SelectState();
    ~SelectState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
    bool handleEvent(SDL_Event&);
    void clearLevels();
private:
    static std::string worlds[NUM_WORLDS];
    std::vector<TextTexture*> world_textures;
    std::vector<TextTexture*> level_textures;
    static std::map<std::string, std::vector<std::string>> world_map;
    CurrSelectState curr_state;
    TextTexture backText;
    int selected_world;
    int selected_level;
};

#endif
