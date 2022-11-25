#include <iostream>
#include "heroCar.hpp"
#include "Drawing.hpp"
#include "PoliceCar.hpp"

#include <SDL.h>
using namespace std;

class SprintCar{
    public:
    
    heroCar *h;
    // PoliceCar *p;
    
    void CreateObject(int );
    void DrawObject();
    void move(SDL_Keycode key);

};