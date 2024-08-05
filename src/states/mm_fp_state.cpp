#include <iostream>

#include "states/mm_fp_state.hpp"
#include "states/colors.hpp"

MMFPState::MMFPState()
{
    curr_selected = 0;
}

MMFPState::~MMFPState()
{
    close();
}

bool MMFPState::init(int* w, int* h, SDL_Renderer* r)
{
    BaseState::init(w, h ,r);

    songs[0].path = "its-a-me";
    songs[0].display = "It's a me";
    songs[1].path = "starman-slaughter";
    songs[1].display = "Starman Slaughter";
    songs[2].path = "apparition";
    songs[2].display = "Apparition";
    songs[3].path = "thalassophobia";
    songs[3].display = "Thalassophobia";
    songs[4].path = "dark-forest";
    songs[4].display = "Dark Forest";
    songs[5].path = "alone";
    songs[5].display = "Alone";
    songs[6].path = "oh-god-no";
    songs[6].display = "Oh God No";
    songs[7].path = "i-hate-you";
    songs[7].display = "I Hate You";
    songs[8].path = "dictator";
    songs[8].display = "Dictator";
    songs[9].path = "promotion";
    songs[9].display = "Promotion";
    songs[10].path = "abandoned";
    songs[10].display = "Abandoned";
    songs[11].path = "the-end";
    songs[11].display = "The End";
    songs[12].path = "no-hope";
    songs[12].display = "No Hope";
    songs[13].path = "golden-land";
    songs[13].display = "Golden Land";
    songs[14].path = "last-course";
    songs[14].display = "Last Course";
    songs[15].path = "no-party";
    songs[15].display = "No Party";
    songs[16].path = "paranoia";
    songs[16].display = "Paranoia";
    songs[17].path = "powerdown";
    songs[17].display = "Powerdown";
    songs[18].path = "demise";
    songs[18].display = "Demise";
    songs[19].path = "all-stars";
    songs[19].display = "All Stars";
    songs[20].path = "overdue";
    songs[20].display = "Overdue";
    songs[21].path = "nourishing-blood";
    songs[21].display = "Nourishing Blood";
    songs[22].path = "bad-day";
    songs[22].display = "Bad Day";
    songs[23].path = "so-cool";
    songs[23].display = "So Cool";
    songs[24].path = "race-traitors";
    songs[24].display = "Race-traitors";
    songs[25].path = "mario-sing-and-game-rythm-9";
    songs[25].display = "MARIO SING AND GAME RYTHM 9";
    songs[26].path = "day-out";
    songs[26].display = "Day Out";
    songs[27].path = "unbeatable";
    songs[27].display = "Unbeatable";

    for (int i = 0; i < NUM_SONGS; ++i)
    {
        if (!songs[i].artwork.loadFromFile("./assets/mm_fp/" + songs[i].path + ".webp", renderer))
            return false;
        songs[i].artwork.setRGBA(0xff, 0, 0);
    }

    if (!song_name.openFont("./assets/Mario64.ttf") || !song_name.loadFromText(songs[0].display, red, renderer))
        return false;
    return true;
}

void MMFPState::close()
{
    for (int i = 0; i <NUM_SONGS; ++i)
        songs[i].artwork.free();
    curr_selected = 0;
}

void MMFPState::render()
{
    int art_y = (*height - songs[curr_selected].artwork.getHeight()) / 2;
    songs[curr_selected].artwork.render(renderer, (*width - songs[curr_selected].artwork.getWidth()) / 2, art_y);
    song_name.render(renderer, (*width - song_name.getWidth()) / 2, 700);
}

void MMFPState::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
        switch (e.key.keysym.sym)
        {
            case SDLK_RIGHT:
            case SDLK_LEFT:
                if (e.key.keysym.sym == SDLK_RIGHT)
                {
                    if (++curr_selected >= NUM_SONGS)
                        curr_selected = 0;
                }
                else
                {
                    if (--curr_selected <= -1)
                        curr_selected = NUM_SONGS - 1;
                }
                song_name.loadFromText(songs[curr_selected].display, red, renderer);
                break;
        }
}
