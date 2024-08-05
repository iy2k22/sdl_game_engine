#ifndef MM_FP_STATE_HPP
#define MM_FP_STATE_HPP

#include <string>

#include "base_state.hpp"
#include "../textures/image_texture.hpp"
#include "../textures/text_texture.hpp"

const int NUM_SONGS = 28;

typedef struct song_entry {
    std::string path, display;
    ImageTexture artwork;
} SongEntry;

class MMFPState : public BaseState
{
public:
    MMFPState();
    ~MMFPState();
    bool init(int*, int*, SDL_Renderer*);
    void close();
    void render();
    void handleEvent(SDL_Event&);
private:
    int curr_selected;
    SongEntry songs[NUM_SONGS];
    TextTexture song_name;
};

#endif
