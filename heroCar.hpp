#include <iostream>
#include "car.hpp"
#include <SDL.h>
#include "Fire.hpp"
#pragma once
#include"Bullets.hpp"
using namespace std;

class heroCar:public car{
    private:
    int speed;
    int score;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite; 
    Fire* f;
    //sprite value
    vector<Bullets*> b; 
  
    
    //Score s;
    //Health h;

    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    void shootFire();
    SDL_Rect getRect();
};
