#include "car.hpp"

class PoliceCar: public car{
    int speed;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite = {15,27, 139,256};


    PoliceCar();
    void Draw();
    void Drive();
    
};