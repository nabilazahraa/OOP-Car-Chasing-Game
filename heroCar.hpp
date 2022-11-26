#include <iostream>
#include "car.hpp"
#include <SDL.h>
#include "Fire.hpp"
#pragma once

class heroCar:public car{
    private:
    int speed;
    int score;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite; 
    Fire* f;
    //sprite value
    
    //SDL_Rect sprite ;
    public:
    
    //Score s;
    //Health h;

    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    void shootFire();
    SDL_Rect getRect();
};