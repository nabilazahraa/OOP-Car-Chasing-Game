#include <iostream>
#include <SDL.h>
#pragma once

class car{
    protected:

    int speed;
    SDL_Rect srcRect, moverRect;
    // SDL_Rect moverRect;
    // SDL_Rect sprite; 
    
    public:
    car();
    void setRect(int x, int y, int w, int h);
    void setmoverRect(int x, int y, int w, int h);
    SDL_Rect getmoverRect();
    //virtual draw function
    virtual void Draw()= 0;

    //herocar drive function
    virtual void DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    //normalcar and policecar drive function 
    virtual void DriveCar();

    virtual void DriveNormalCar(SDL_Rect,int);
    virtual int getDirection();

    
};