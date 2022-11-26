#include <iostream>
#include <SDL.h>
#pragma once
class Bullets
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite= {2115,23,62,170};
    SDL_Rect sprite1={1913,1,107,194};
    public:
        void Draw(char);
        Bullets();
        Bullets(int x,int y);
        void ShootBullets(char s);
};
