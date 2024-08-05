#ifndef MM_FP_BOX_HPP
#define MM_FP_BOX_HPP

#include <string>

#include "../textures/image_texture.hpp"

class MMFPBox
{
public:
    MMFPBox();
    ~MMFPBox();
    bool init(std::string, SDL_Renderer*);
    void close();
    void render(SDL_Renderer*);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    int getWidth();
    int getHeight();
private:
    int x;
    int y;
    ImageTexture texture;
};

#endif
