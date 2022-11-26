#include "car.hpp"
#include <iostream>
#include <SDL.h>
#include<iostream>
#include"Drawing.hpp"
#include<cstdlib>
class NormalCar: public car
{
    private:
        int speed;
        SDL_Rect srcRect, moverRect;
        SDL_Rect sprite1={2472,22,125,231};
        SDL_Rect sprite2={3122,16,114,279};
        SDL_Rect sprite3={3251,30,123,231};
        int random=rand()%3;
    public:
        NormalCar();
        void Draw();
        void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
};
