#include <iostream>
#include "car.hpp"
#include "heroCar.hpp"
#include "Drawing.hpp"
#include "PoliceCar.hpp"
#include "NormalCar.hpp"
#include<vector>
#include"Bullets.hpp"
#include<SDL.h>
using namespace std;

class SprintCar{
    public:
    
    car *h; //herocar

    car *p;
    vector<car*>n;
    long int count=2;

    void CreateHero(int );
    void DrawObject();
    void move(SDL_Keycode key);
    void moveCars();
};
