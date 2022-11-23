#include <iostream>
#include "car.hpp"
#include <SDL.h>
#pragma once

class heroCar:public car{
    private:
    int speed;
    int score;
    SDL_Rect srcRect, moverRect;
<<<<<<< HEAD
    SDL_Rect sprite = {0,0,143,262}; 
    //sprite value
    
=======
    SDL_Rect sprite ;
    //Bullet b;
    //Score s;
    //Health h;
>>>>>>> f94fd06ca8cc937f9ad6bbc394a9bc990ee546c8

    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
    
};