#include <iostream>
#include <SDL.h>
#include "car.hpp"
#pragma once
class Bullets
{
    private:
    SDL_Rect srcRect= {2115,23,62,170};
    SDL_Rect moverRect;
    SDL_Rect Boom={3539,68,312,304};
    SDL_Rect BoomMove;
    
    public:
        bool gone=false;
        void Draw();
        Bullets();
        Bullets(int x,int y);
        void ShootBullets();
        // void collision();
        void Mask(car* p,car*);
        SDL_Rect* getMover();
};
