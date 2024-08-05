#include "states/mm_fp_box.hpp"

MMFPBox::MMFPBox()
{
    x = y = 0;
}

MMFPBox::~MMFPBox()
{
    close();
}

bool MMFPBox::init(std::string path, SDL_Renderer* renderer)
{
    if (!texture.loadFromFile(path, renderer))
        return false;
    texture.setRGBA(0xff, 0, 0);
    texture.scale(0.7);
    return true;
}

void MMFPBox::close()
{
    texture.free();
    x = y = 0;
}

void MMFPBox::render(SDL_Renderer* renderer)
{
    texture.render(renderer, x, y);
}

int MMFPBox::getX()
{
    return x;
}

int MMFPBox::getY()
{
    return y;
}

void MMFPBox::setX(int newX)
{
    x = newX;
}

void MMFPBox::setY(int newY)
{
    y = newY;
}

int MMFPBox::getHeight()
{
    return texture.getHeight();
}

int MMFPBox::getWidth()
{
    return texture.getWidth();
}
