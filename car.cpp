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

SDL_Rect car::getmoverRect()
{
    return moverRect;
}

SDL_Rect* car::getMoverRect()
{
    return &moverRect;
}
//defined in heroCar
void car::DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{}

void car::DriveCar()
{}

void car::DriveNormalCar(car* ,SDL_Rect,int)
{}

bool car::Mask(car* h)
{

}

int car::getDirection()
{}

void car::DisplayScore()
{};

void car::DrawBullets(car* p,car*)
{

};
void car::DrawBullets(car*)
{

};
void car::IncreaseScore(){};
void car::DecreaseScore(){};

void car::DecreaseHealth(){};

int car::getLife(){};

