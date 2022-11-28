#include "Fire.hpp"
#include "Drawing.hpp"

void Fire::Draw(char x)
{
    // if(x=='h')
    // srcRect=sprite;
    // else
    // srcRect=sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

Fire::Fire()
{
    moverRect={440,320,20,20};
}

Fire::Fire(int x, int y)
{
    moverRect={x,y+40,40,40};
}

void Fire::ShootFire(char s)
{
    // if(s=='h')
    //     moverRect.y-=35;
    // else
        moverRect.y+=30;
}
