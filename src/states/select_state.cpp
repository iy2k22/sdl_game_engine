#include "states/select_state.hpp"
#include "states/colors.hpp"
#include "textures/text_texture.hpp"

std::string SelectState::worlds[] = {
    "Mushroom Kingdom",
    "Irregularity Isle",
    "Woodland of Lies",
    "Content Cosmos",
    "Hellish Heights",
    "Classified Castle"
};

std::map<std::string, std::vector<std::string>> SelectState::world_map = {
{"Mushroom Kingdom", {"Its a me", "Starman Slaughter", "All Stars"}},
{"Irregularity Isle", {"So Cool", "Nourishing Blood", "MARIO SING AND GAME RYTHM 9"}},
{"Woodland of Lies", {"Alone", "Oh God No", "I Hate You", "Thalassophobia", "Apparition", "Last Course", "Dark Forest"}},
{"Content Cosmos", {"Bad Day", "Day Out", "Dictator", "Race traitors", "No Hope"}},
{"Hellish Heights", {"Unbeatable", "Golden Land", "No Party", "Paranoia", "Overdue", "Powerdown", "Demise"}},
{"Classified Castle", {"Promotion", "Abandoned", "The End"}}
};

SelectState::SelectState()
{
    selected_world = selected_level = 0;
    curr_state = WORLD;
}

SelectState::~SelectState()
{
    close();
}

bool SelectState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h, r);
    if (!backText.openFont("./assets/font.ttf") || !backText.loadFromText("Backspace to return", black, renderer))
        return false;
    for (int i = 0; i < NUM_WORLDS; ++i)
    {
        world_textures.push_back(new TextTexture);
        if (!world_textures[i]->openFont("./assets/font.ttf") || !world_textures[i]->loadFromText(worlds[i], i == 0 ? red : black, renderer))
            return false;
    }
    return true;
}

void SelectState::close()
{
    clearLevels();
    for (auto a : world_textures)
        if (a != nullptr)
        {
            a->free();
            a = nullptr;
        }
    world_textures.clear();
    backText.free();
    curr_state = WORLD;
    selected_world = selected_level = 0;
}

void SelectState::render()
{
    switch (curr_state)
    {
        case WORLD:
            static int startPointWorld = (*height - (world_textures[0]->getHeight() * NUM_WORLDS)) / 2;
            for (int i = 0; i < NUM_WORLDS; ++i)
                world_textures[i]->render(renderer, (*width - world_textures[i]->getWidth()) / 2, startPointWorld + (world_textures[i]->getHeight() * i));
            break;
        case LEVEL:
            int numLevels = level_textures.size();
            int startPoint = (*height - (level_textures[0]->getHeight() * numLevels)) / 2;
            for (int i = 0; i < numLevels; ++i)
                level_textures[i]->render(renderer, (*width - level_textures[i]->getWidth()) / 2, startPoint + (level_textures[i]->getHeight() * i));
            backText.render(renderer, 0, *height - backText.getHeight());
            break;
    }
}

bool SelectState::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN)
        switch (e.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_DOWN:
                if (curr_state == WORLD)
                {
                    world_textures[selected_world]->loadFromText(worlds[selected_world], black, renderer);
                    if (e.key.keysym.sym == SDLK_DOWN)
                    {
                        if (++selected_world >= NUM_WORLDS)
                            selected_world = 0;
                    }
                    else
                    {
                        if (--selected_world <= -1)
                            selected_world = NUM_WORLDS - 1;
                    }
                    world_textures[selected_world]->loadFromText(worlds[selected_world], red, renderer);
                    break;
                }
                break;
            case SDLK_RETURN:
                if (curr_state == WORLD)
                {
                        int num_levels = world_map[worlds[selected_world]].size();
                        for (int i = 0; i < num_levels; ++i)
                        {
                            level_textures.push_back(new TextTexture);
                            if (!level_textures[i]->openFont("./assets/font.ttf") || !(level_textures[i]->loadFromText(world_map[worlds[selected_world]][i], black, renderer)))
                                return false;
                        }
                        curr_state = LEVEL;
                        break;
                }
                break;
            case SDLK_BACKSPACE:
                if (curr_state == LEVEL)
                {
                    clearLevels();
                    curr_state = WORLD;
                }
        }
    return true;
}

void SelectState::clearLevels()
{
    for (auto a : level_textures)
        if (a != nullptr)
        {
            a->free();
            a = nullptr;
        }
    level_textures.clear();
}
