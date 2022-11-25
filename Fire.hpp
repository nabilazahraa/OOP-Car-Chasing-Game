#include <iostream>
#include <SDL.h>
#pragma once
class Fire
{
    public:
    SDL_Rect srcRect = {1913,1,107,194};
    SDL_Rect moverRect;
    bool alive;

    public:
    Fire();
    void Draw();
    void Shoot();
    void update(SDL_Rect);
};