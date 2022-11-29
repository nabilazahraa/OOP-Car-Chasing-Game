#include <iostream>
#include <SDL.h>
#pragma once

class Fire
{
    public:
    SDL_Rect srcRect = {1913,1,107,194};
    SDL_Rect moverRect;

    public:
    void Draw();
        Fire();
        Fire(int x,int y);
        void ShootFire();
        // void collision();
};
