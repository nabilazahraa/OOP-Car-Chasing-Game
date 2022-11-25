#include <iostream>
#include "heroCar.hpp"
#include "Drawing.hpp"
#include "PoliceCar.hpp"
#include "NormalCar.hpp"

#include <SDL.h>
using namespace std;

class SprintCar{
    public:
    
    heroCar *h;
    PoliceCar *p;
    //NormalCar vector

    void CreateHero(int );
    void DrawObject();
    void move(SDL_Keycode key);
    void CreatePolice();
    

};