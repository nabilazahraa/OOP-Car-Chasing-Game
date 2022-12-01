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
    //hero car function for bullets
    virtual void DrawBullets(car* p, car*);
    //police car funtion for bullets
    virtual void DrawBullets(car*);
    //increase score of hero car
    virtual void IncreaseScore();
    //decrease health of hero car
    virtual void DecreaseHealth();
    //return health of hero car
    virtual int getLife();
    //decrease score of hero car
    virtual void DecreaseScore();
    //mask for 
    virtual bool Mask(car* h);
    
};