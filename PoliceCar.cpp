#include "PoliceCar.hpp"
#include <iostream>
#include <SDL.h>

//draw police car
void PoliceCar::Draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
};

//Initialize police car values
PoliceCar::PoliceCar()
{
    setmoverRect(500,50, 100, 120);
    setRect(1136,27, 139,256);
    direction = 1;
    
};

//drive police car
void PoliceCar::DriveCar()
{
    //moving car left and right 
    if(direction ==1)
    {
        moverRect.x +=30;
    }
    else 
    {
        moverRect.x-=30;
    }

    //change direction if touching boundary
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

//draw bullets of police car
void PoliceCar::DrawBullets(car* h)
{
    for(int i=0;i<fires.size();i++)
    {
        fires[i]->Draw(); //draw fire
        fires[i]->ShootFire(); //movement of fire
        fires[i]->Mask(h); //collision with hero car
        //delete fire if missed
        if(fires[i]->firegone==true)
        {
            fires.erase(i+fires.begin());
        }
        
    }
}

//destructor of police car
PoliceCar::~PoliceCar()
{
    for(int i=0;i<fires.size();i++)
    {
        delete fires[i];
    }
    fires.clear();
}
