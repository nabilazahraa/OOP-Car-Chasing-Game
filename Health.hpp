#include <iostream>
#include <SDL.h>
#pragma once
class Health
{
    private:
    int lives;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite[4]={{779,8,187,49},{779,59,148,50},{779,111,109,50},{778,163,80,50}};

    public:
    Health();
    //operator overloading to decrease life
    void operator --(); 
    int getlives();
    void Draw();

};