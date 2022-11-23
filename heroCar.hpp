#include <iostream>
#include "car.hpp"
#include <SDL.h>

class heroCar:public car{
    public:
    // int speed;
    int score;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite = {0,0,143,262}; 
    //sprite value
    

    public:
    // void Drive(); //runtime polymorphism
    //draw function 
    heroCar();
    void Draw();
    void Drive(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key);
    
    
};