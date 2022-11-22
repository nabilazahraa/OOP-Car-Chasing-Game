#include "heroCar.hpp"
#include "Drawing.hpp"


//Draw the car on the screen
void heroCar::Draw(){
    srcRect = sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    

}

//initializes heroCar according to the sprite values of 
//sports car, bike or wagon.
heroCar::heroCar(int x, int y, int w, int h )
{
    moverRect = {390,590, 100, 200};
    speed = 5;
    sprite.x = x;
    sprite.y = y;
    sprite.w = w;
    sprite.h = h;

}

//Drive car using arrow keys
void heroCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
    if (key == SDLK_UP){
        if(moverRect.y>0) //not move out of screen in y axis
         moverRect.y-=5*speed;
    }
    else if (key == SDLK_DOWN) {
        if(moverRect.y<600) //not move out of screen in y axis
        moverRect.y+=5*speed;
    }
    else if (key == SDLK_RIGHT) {
        if(moverRect.x<710) //not move out of screen in x axis
        moverRect.x+=5*speed;
    }
    else if (key == SDLK_LEFT) {
        if(moverRect.x>200) //not move out of screen in x axis
        moverRect.x-=5*speed;
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
