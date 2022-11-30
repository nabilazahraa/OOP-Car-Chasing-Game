#include "Bullets.hpp"
#include "Bullets.hpp"
#include<iostream>
#include"Drawing.hpp"
#include<SDL.h>
#include"heroCar.hpp"

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

SDL_Rect* Bullets::getMover()
{
    return &moverRect;
}

bool Bullets::Mask(car* p, car* h)
{   
    bool collision = SDL_HasIntersection(getMover(), p->getMoverRect());
    if(collision == true)
    { 
        h->IncreaseScore();
        BoomMove={moverRect.x,moverRect.y,60,60};
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &Boom, &BoomMove);
        moverRect.y=-30;
    }
    return collision;
}
