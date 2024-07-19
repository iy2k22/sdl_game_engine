#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "states/animated_state.hpp"

AnimatedState::AnimatedState()
{
    ;
}

AnimatedState::~AnimatedState()
{
    close();
}

bool AnimatedState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h, r);
    if (!nes_mario.loadFromFile("./assets/nes_mario.png", renderer))
        return false;
    std::ifstream anim_file;
    anim_file.open("./assets/running_anim.csv");
    if (!anim_file.is_open())
    {
        std::cerr << "Error: could not open animation file!\n";
        return false;
    }
    std::string currLine, currValue;
    std::vector<int> row;
    while (std::getline(anim_file, currLine))
    {
        row.clear();
        std::stringstream ok(currLine);
        while (std::getline(ok, currValue, ','))
            row.push_back(std::stoi(currValue));
        running_anim.push_back({row[0], row[1], row[2], row[3]});
    }
    anim_file.close();
    return true;
}

void AnimatedState::close()
{
    nes_mario.free();
    BaseState::close();
}

void AnimatedState::render()
{
    static int curr_frame = 0;
    SDL_Rect* curr_clip = &running_anim[curr_frame / 5];
    nes_mario.render(renderer, (*width - curr_clip->w) / 2, (*height - curr_clip->h) / 2, curr_clip);
    ++curr_frame;
    if ((curr_frame / 5) >= NUM_FRAMES)
        curr_frame = 0;
}
