#include <iostream>
#include "heroCar.hpp"
#include "Drawing.hpp"
// #include "policeCar.hpp"
#include <SDL.h>
using namespace std;

class SprintCar{
    public:
    
    heroCar h;
    // policeCar p*;


    
    void CreateObject();
    void DrawObject();
    void move(SDL_Keycode key);

};