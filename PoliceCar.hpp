#include "car.hpp"
#include <SDL.h>
#include <iostream>
#include "Drawing.hpp"
#include "Fire.hpp"
#include<vector>
#pragma once
using namespace std;
class PoliceCar : public car
{
    private:
        // int speed;
        int direction;
        int random;
        // SDL_Rect srcRect= {1136,27, 139,256};
        // SDL_Rect moverRect;
        
        int fram=0;

    public:
        vector<Fire*> fires; 
        PoliceCar();
        void Draw();
        void DriveCar();
        int getDirection();
        void DrawBullets(car* h);
};
