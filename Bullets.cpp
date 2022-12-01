#include "Bullets.hpp"
#include "Bullets.hpp"
#include<iostream>
#include"Drawing.hpp"
#include<SDL.h>
#include"heroCar.hpp"

//draw bullets
void Bullets::Draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//Initializes bullets
Bullets::Bullets()
{
    moverRect={440,320,20,20};
}

//Initializes bullets according to car position
Bullets::Bullets(int x, int y)
{
    moverRect={x,y,20,30};
}

//move the bullets
void Bullets::ShootBullets()
{
        moverRect.y-=35;
        if(moverRect.y<=-10)
        {
            gone=true;
        }
}

//return position of bullet
SDL_Rect* Bullets::getMover()
{
    return &moverRect;
}

//collision of bullets with car
void Bullets::Mask(car* p, car* h)
{   
    bool collision = SDL_HasIntersection(getMover(), p->getMoverRect());
    if(collision == true)
    { 
        h->IncreaseScore(); //increase score of hero car if collision 
        BoomMove={moverRect.x,moverRect.y,60,60};
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &Boom, &BoomMove);
        moverRect.y=-30;
    }
    
}
