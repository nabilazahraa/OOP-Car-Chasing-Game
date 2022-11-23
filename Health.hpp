#include <iostream>
#include <SDL.h>

class Health
{
    int lives;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite;

    public:
    Health();
    void DecreaseLife();
    

};