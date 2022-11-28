#include "Bullets.hpp"
#include "Bullets.hpp"
#include<iostream>
#include"Drawing.hpp"
#include<SDL.h>
#include"heroCar.hpp"

void Bullets::Draw(char x)
{
    // if(x=='h')
    // srcRect=sprite;
    // else
    // srcRect=sprite1;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

Bullets::Bullets()
{
    moverRect={440,320,20,20};
}

Bullets::Bullets(int x, int y)
{
    moverRect={x,y,20,30};
}

void Bullets::ShootBullets(char s)
{
    if(s=='h')
        moverRect.y-=35;
    else
        moverRect.y+=30;
}
