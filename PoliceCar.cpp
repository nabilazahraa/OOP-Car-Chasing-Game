#include "PoliceCar.hpp"
#include <iostream>
#include <SDL.h>

void PoliceCar::Draw()
{
    //draw fires
    // for(int i=0;i<fires.size();i++)
    // {
    //     fires[i]->Draw();
    //     fires[i]->ShootFire();
        
    // }

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

//Initialize police car values
PoliceCar::PoliceCar()
 {
    // int r=200+(rand()%550);
    setmoverRect(500,50, 100, 120);
    setRect(1136,27, 139,256);
    direction = 1;
    
};

void PoliceCar::DriveCar()
{
    // int random2=25+(rand()%35);
    // if(moverRect.y<20)
    //     moverRect.y+=25;
        
    // random=rand()%10;

    // if(random==0)
    // {
    //     if(moverRect.x+random2>1000)
    //         moverRect.x-=random2;   
    //     else
    //         moverRect.x+=random2;
    // }

    // if(random==1)
    // {
    //     if(moverRect.x-random2<300)
    //         moverRect.x+=random2;
    //     else
    //         moverRect.x-=random2;
    // }

    //moving car left and right 
    if(direction ==1)
    {
        moverRect.x +=30;
    }
    else 
    {
        moverRect.x-=30;
    }
    if(moverRect.x<=300 || moverRect.x>=1100)
    {
        direction *=-1;
    }

    //shoot fire
    fram++;
    if(fram== 10)
    {
        Fire* f =new Fire(moverRect.x,moverRect.y);
        fires.push_back(f);
        fram = 0;
    }
    
};

//return direction of police car movement
int PoliceCar::getDirection()
{
    return direction;
}
void PoliceCar::DrawBullets(car* h)
{
    for(int i=0;i<fires.size();i++)
    {
        fires[i]->Draw();
        fires[i]->ShootFire();
        fires[i]->Mask(h);
        if(fires[i]->firegone==true)
        {
            fires.erase(i+fires.begin());
        }
        
    }
}
PoliceCar::~PoliceCar()
{
        for(int i=0;i<fires.size();i++)
    {
        delete fires[i];
    }
    fires.clear();
}
