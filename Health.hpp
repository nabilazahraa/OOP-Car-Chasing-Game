#include <iostream>
#include <SDL.h>

class Health
{
    int lives;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite[4]={{779,8,187,49},{779,59,148,50},{779,111,109,50},{778,163,80,50}};

    public:
    Health();
    void DecreaseLife();
    void Draw();

};