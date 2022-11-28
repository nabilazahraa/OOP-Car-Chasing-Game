#include "car.hpp"
#include <iostream>
#include <SDL.h>
#include<iostream>
#include"Drawing.hpp"
#include<cstdlib>
class NormalCar : public car
{
    private:
        int speed;
        // SDL_Rect srcRect, moverRect;
        SDL_Rect sprite1={2738,22,125,231};
        SDL_Rect sprite2={2907,16,114,279};
        SDL_Rect sprite3={3036,30,123,231};
        int random=rand()%3;
        
    public:
        NormalCar(int);
        void Draw();
        void DriveNormalCar(SDL_Rect, int);
};
