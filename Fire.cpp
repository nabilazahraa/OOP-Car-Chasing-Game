#include "Fire.hpp"
#include "Drawing.hpp"


Fire::Fire()
{
    moverRect = {390,590, 50, 80};
    alive ==false;
}
void Fire::Draw()
{
    // int x,int y
    // srcRect = sprite;
    if(alive ==true)
    {
        // moverRect.x = car.x;
        // moverRect.y = car.y;
        
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    }

}

void Fire::update(SDL_Rect car)
{
    moverRect.x = car.x + 20;
    moverRect.y = car.y - 70;
}

void Fire::Shoot()
{
    if(alive == true)
    {
    moverRect.y -=10;
    }
    else if(moverRect.y<0)
    {
        alive == false;
    }
    
    
}
