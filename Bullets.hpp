#include <iostream>
#include <SDL.h>
#pragma once
class Bullets
{
    SDL_Rect srcRect= {2115,23,62,170};
    SDL_Rect moverRect;
    
    public:
        void Draw(char);
        Bullets();
        Bullets(int x,int y);
        void ShootBullets(char s);
        void collision();
};
