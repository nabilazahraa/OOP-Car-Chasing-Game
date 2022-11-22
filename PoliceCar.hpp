#include "car.hpp"
#include <SDL.h>
#include <iostream>
#include "Drawing.hpp"
#pragma once
class PoliceCar: public car{
    private:
    int speed;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite = {15,27, 139,256};

    public:
    PoliceCar();
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
};