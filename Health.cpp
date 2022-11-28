#include "Health.hpp"
#include "Drawing.hpp"

Health::Health()
{
    lives = 3;
    srcRect = sprite[0];
    moverRect = {1300, 5, 150, 50};
}

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
    
    if(lives == 0)
    {
        //end game
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//operator overloading to decrease lives
void Health:: operator --()
{
    --lives;

}

int Health::getlives()
{
    return lives;
}