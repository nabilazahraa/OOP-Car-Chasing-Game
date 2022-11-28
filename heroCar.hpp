#include <iostream>
#include "car.hpp"
#include <SDL.h>
#include<vector>
#include"Bullets.hpp"
#include "Score.hpp"
#include "Health.hpp"
#include "Fire.hpp"
#pragma once

using namespace std;

class heroCar:public car{
    private:
    // int speed;
    Score score;
    Health h;
    SDL_Rect moverRect;
    SDL_Rect sprite; 
    int fram=0;

    // Fire* f;
    //sprite value
    vector<Bullets*> b;


    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    void shootFire();
    SDL_Rect getRect();
};
