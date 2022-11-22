#include "PoliceCar.hpp"
#include <iostream>
#include <SDL.h>

 PoliceCar::PoliceCar()
 {
    moverRect = {210,100, 90, 150};
    speed = 5;
 };
void PoliceCar::Draw()
{
    srcRect = sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};
void PoliceCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
};