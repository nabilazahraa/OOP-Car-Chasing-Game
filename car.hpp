#include <iostream>
#include <SDL.h>
#pragma once

class car{
    protected:

    int speed;
    // SDL_Rect moverRect;
    // SDL_Rect sprite; 
    
    public:
    car();
    
    //virtual draw function
    virtual void Draw()= 0;

    //herocar drive function
    virtual void DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    //normalcar and policecar drive function 
    virtual void DriveCar(SDL_Renderer* gRenderer, SDL_Texture* assets);

    
};