#include "heroCar.hpp"
#include "Drawing.hpp"



//Draw the car on the screen
void heroCar::Draw(){
    srcRect = sprite;
    for(int i=0;i<b.size();i++)
    {
        b[i]->Draw('h');
        b[i]->ShootBullets('h');
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    

}

//initializes heroCar according to the sprite values of 
//sports car, bike or wagon.
heroCar::heroCar(int x, int y, int w, int h )
{
    moverRect = {390,590, 50, 80};
    sprite.x = x;
    sprite.y = y;
    sprite.w = w;
    sprite.h = h;
    f = new Fire();
}

//Drive car using arrow keys
void heroCar::Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
    if (key == SDLK_UP || key== SDLK_w){
        if(moverRect.y>30) //not move out of screen in y axis
         moverRect.y-=30;
    }
    else if (key == SDLK_DOWN || key==SDLK_s) {
        if(moverRect.y<640) //not move out of screen in y axis
        moverRect.y+=30;
    }
    else if (key == SDLK_RIGHT || key==SDLK_d) {
        if(moverRect.x<580) //not move out of screen in x axis
        moverRect.x+=35;
    }
    else if (key == SDLK_LEFT || key==SDLK_a) {
        if(moverRect.x>150) //not move out of screen in x axis
        moverRect.x-=35;
    }
    else if(key== SDLK_b){
        Bullets *b1=new Bullets(moverRect.x,moverRect.y);
        b.push_back(b1);
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void heroCar::shootFire()
{
    // f->Draw(moverRect.x, moverRect.y);
    f->Shoot();
    
}

SDL_Rect heroCar::getRect()
{
    return moverRect;
}


