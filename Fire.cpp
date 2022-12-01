#include "Fire.hpp"
#include "Drawing.hpp"

//draw fire 
void Fire::Draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//Initialize Fire values
Fire::Fire()
{
    moverRect={440,320,20,20};
}

//Initialize Fire position according to car position
Fire::Fire(int x, int y)
{
    moverRect={x,y+40,40,40};
}

//move fire on scren
void Fire::ShootFire()
{
    moverRect.y+=30;
    if (moverRect.y>=820)
    {
        firegone=true;
    }
}


//return positon of Fire
SDL_Rect* Fire::getMover()
{
    return &moverRect;
}

//collision of fire with car
bool Fire::Mask(car* h)
{
    bool collision = SDL_HasIntersection(getMover(), h->getMoverRect());
    if(collision == true)
    { 
        h->DecreaseHealth(); //decrease health of hero car if collsion
        BoomMove={moverRect.x,moverRect.y,60,60};
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &Boom, &BoomMove);
        moverRect.y=820;
    }
    return collision;
    
}
