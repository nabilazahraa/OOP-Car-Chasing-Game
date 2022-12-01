#include "finish.hpp"

//draw finishline
void finishLine::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

//move finish line
void finishLine::move()
{
    moverRect.y+=10;
}
