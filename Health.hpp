#include <iostream>
#include <SDL.h>

class Health
{
    int lives;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite[4]={{994,8,187,49},{994,59,148,50},{994,111,109,50},{993,163,80,50}};

    public:
    Health();
    void DecreaseLife();
    

};