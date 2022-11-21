#include "car.hpp"

class NormalCar: public car{
    int speed;
    SDL_Rect srcRect, moverRect;
    SDL_Rect sprite ;

    NormalCar(int, int, int, int);
    void Draw();
    void Drive();
};