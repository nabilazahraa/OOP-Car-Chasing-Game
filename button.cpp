#include "button.hpp"

button::button()
{
    rect.x = 150;
    rect.y = 380;
    rect.h = 50;
    rect.w = 200;
}

button::~button()
{

}

void button::draw(int x1, int y1, int w1, int h1, int xr, int yr, int wr, int hr)
{
    rect.x = xr;
    rect.y = yr;
    rect.h = hr;
    rect.w = wr;

    sprite.x = x1;
    sprite.y= y1;
    sprite.w = w1;
    sprite.h = h1;

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &sprite, &rect);
}