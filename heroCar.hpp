#include <iostream>
#include "car.hpp"
#include <SDL.h>

class heroCar:public car{
    public:
    int speed;
    int score;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite ;
    //sprite value
    

    public:
    
    heroCar(int, int, int, int);
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
    
};