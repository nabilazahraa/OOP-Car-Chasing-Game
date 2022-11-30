#include "Health.hpp"
#include "Drawing.hpp"

//initialize values
Health::Health()
{
    lives = 3;
    srcRect = sprite[0]; //full health 
    moverRect = {1300, 5, 150, 50}; 
}

//choose sprite value of health according to 
//the number of lives 
void Health::Draw()
{
    int spriteVal = 3-lives;
    srcRect = sprite[spriteVal];
    
    if(spriteVal == 1)
    {
        moverRect = {1300, 5, 100, 50};
    }
    else if(spriteVal == 2)
    {
        moverRect = {1300, 5, 80, 50};
    }
    else if(spriteVal == 3)
    {
        moverRect = {1300, 5, 70, 50};
    }
    
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//operator overloading to decrease lives
void Health:: operator --()
{
    --lives;
}

//get lives left
int Health::getlives()
{
    return lives;
}