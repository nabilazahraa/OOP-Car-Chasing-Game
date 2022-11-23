#include <iostream>
#include "car.hpp"
#include <SDL.h>
#pragma once

class heroCar:public car{
    private:
    int speed;
    int score;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite = {0,0,143,262}; 
    //sprite value
    
    //SDL_Rect sprite ;
    //Bullet b;
    //Score s;
    //Health h;

    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
    
};