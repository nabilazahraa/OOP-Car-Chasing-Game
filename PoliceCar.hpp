#include "car.hpp"
#include <SDL.h>
#include <iostream>
#include "Drawing.hpp"
#pragma once
using namespace std;
class PoliceCar: public car{
    private:
    int speed;
    int random;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite = {1351,27, 139,256};
    
    int fram=0;
    public:
    vector<Bullets*> b2; 
    PoliceCar();
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
};
