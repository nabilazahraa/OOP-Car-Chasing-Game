#include "PoliceCar.hpp"
#include <iostream>
#include <SDL.h>

void PoliceCar::Draw()
{
    for(int i=0;i<b2.size();i++)
    {
        b2[i]->Draw('P');
        b2[i]->ShootBullets('p');
    }
    srcRect = sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};
PoliceCar::PoliceCar()
 {
    int r=140+(rand()%550);
    moverRect = {r,-40, 50, 80};
    
 };
void PoliceCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    int random2=25+(rand()%35);
    if(moverRect.y<10)
    moverRect.y+=25;
    random=rand()%2;
    if(random==0)
    {
        if(moverRect.x+random2>1300)
        moverRect.x-=random2;
        else
        moverRect.x+=random2;
    }
    if(random==1)
    {
        if(moverRect.x-random2<200)
        moverRect.x+=random2;
        else
        moverRect.x-=random2;
    }
    fram++;
    if(fram==10)
    {
        Bullets *bull=new Bullets(moverRect.x,moverRect.y);
        b2.push_back(bull);
        fram=0;
    }
};
