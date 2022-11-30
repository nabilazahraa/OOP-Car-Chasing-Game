#include <iostream>
#include <SDL.h>
#include "car.hpp"
#pragma once
class Bullets
{
    SDL_Rect srcRect= {2115,23,62,170};
    SDL_Rect moverRect;
    
    public:
        void Draw();
        Bullets();
        Bullets(int x,int y);
        void ShootBullets();
        // void collision();
        bool Mask(car* p,car*);
        SDL_Rect* getMover();
};
