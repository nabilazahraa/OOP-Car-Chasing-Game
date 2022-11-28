#include "car.hpp"

car::car()
{
    speed = 5;
}
void car::setRect(int x, int y, int w, int h)
{
    srcRect.x = x;
    srcRect.y = y;
    srcRect.w = w;
    srcRect.h = h;
}
void car::setmoverRect(int x, int y, int w, int h)
{
    moverRect.x = x;
    moverRect.y = y;
    moverRect.w = w;
    moverRect.h = h;
}

SDL_Rect  car::getmoverRect()
{
    return moverRect;
}

void car::DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{

}

void car::DriveCar()
{
    
}

void car::DriveNormalCar(SDL_Rect car, int x)
{
    
}

int car::getDirection()
{}
