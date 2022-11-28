#include "NormalCar.hpp"
#include<iostream>
#include<SDL.h>
#pragma once
void NormalCar::Draw()
{
    if(random==0)
    {
        srcRect=sprite1;    
    }
    if(random==1)
    {
        srcRect=sprite2;    
    }
    if(random==2)
    {
        srcRect=sprite3;
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

NormalCar::NormalCar()
{  
    int r=300+(rand()%900);
    moverRect={r,800, 100, 120};
}

void NormalCar::DriveCar(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    moverRect.y -= 10;
    if(moverRect.y<0)
    {
        moverRect.y= 800;
        int r2=300+(rand()%900);
        moverRect.x=r2;
        random=rand()%3;
    }
}
