#include "heroCar.hpp"
#include "Drawing.hpp"

void heroCar::Draw(){
    srcRect = sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    
    // moverRect.y =(moverRect.y -5);

}


heroCar::heroCar(int x, int y, int w, int h )
{
    moverRect = {390,390, 130, 240};
    speed = 5;
    sprite.x = x;
    sprite.y = y;
    sprite.w = w;
    sprite.h = h;

}


void heroCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
    if (key == SDLK_UP){
         moverRect.y-=5*speed;
    }
    else if (key == SDLK_DOWN) {
        moverRect.y+=5*speed;
    }
    else if (key == SDLK_RIGHT) {
        moverRect.x+=5*speed;
    }
    else if (key == SDLK_LEFT) {
        moverRect.x-=5*speed;
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
