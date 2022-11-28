#include "PoliceCar.hpp"
#include <iostream>
#include <SDL.h>

void PoliceCar::Draw()
{
    for(int i=0;i<fires.size();i++)
    {
        fires[i]->Draw('P');
        fires[i]->ShootFire('p');
    }

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

PoliceCar::PoliceCar()
 {
    int r=200+(rand()%550);
    moverRect = {500,50, 100, 120};
    
 };

void PoliceCar::DriveCar(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    int random2=25+(rand()%35);
    if(moverRect.y<20)
        moverRect.y+=25;
        
    random=rand()%10;

    if(random==0)
    {
        if(moverRect.x+random2>1000)
            moverRect.x-=random2;   
        else
            moverRect.x+=random2;
    }

    if(random==1)
    {
        if(moverRect.x-random2<300)
            moverRect.x+=random2;
        else
            moverRect.x-=random2;
    }

    
    fram++;
    if(fram==10)
    {
        Fire* f =new Fire(moverRect.x,moverRect.y);
        fires.push_back(f);
        fram=0;
    }
};
