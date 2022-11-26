#include "finish.hpp"

void finishLine::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

void finishLine::move()
{
    moverRect.y+=10;
}
