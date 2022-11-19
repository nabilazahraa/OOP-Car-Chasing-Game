#include <iostream>
#include <SDL.h>

class car{
    protected:

    int speed;
    

    public:
    virtual void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key) = 0;
    void draw();
    
};