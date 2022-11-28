#include <iostream>
#include <SDL.h>
#pragma once

class Fire
{
    public:
    SDL_Rect srcRect = {3364,61,107,194};
    SDL_Rect moverRect;
    bool alive;

    public:
    void Draw(char);
        Fire();
        Fire(int x,int y);
        void ShootFire(char s);
        // void collision();
};