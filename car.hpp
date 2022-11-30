#include <iostream>
#include <SDL.h>
#pragma once

class car{
    protected:

    int speed;
    SDL_Rect srcRect, moverRect;
    
    public:
    car();
    void setRect(int x, int y, int w, int h);
    void setmoverRect(int x, int y, int w, int h);

    //return moverRect values
    SDL_Rect* getMoverRect();
     SDL_Rect getmoverRect();
    //virtual draw function
    virtual void Draw()= 0;

    //herocar drive function
    virtual void DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    //policecar drive function 
    virtual void DriveCar();
    //normal car drive function
    virtual void DriveNormalCar(car* ,SDL_Rect,int );
    //police car direction function
    virtual int getDirection();
    //herocar display score function
    virtual void DisplayScore();

    virtual void DrawBullets(car* p, car*);
     virtual void DrawBullets(car*);
    virtual void IncreaseScore();
    virtual void DecreaseHealth();
    virtual int getLife();
    virtual void DecreaseScore();
    virtual bool Mask(car* h);
    
};