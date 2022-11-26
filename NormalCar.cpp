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
    int r=140+(rand()%550);
    moverRect={r,25, 50, 70};
}
void NormalCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    moverRect.y+=20;
    if(moverRect.y>=650)
    {
        moverRect.y=20;
        int r2=140+(rand()%550);
        moverRect.x=r2;
        random=rand()%3;
    }
}
