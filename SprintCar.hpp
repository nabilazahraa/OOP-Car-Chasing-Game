#include <iostream>
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
    
    heroCar *h;
    PoliceCar *p;
    vector<NormalCar*>n;
    long int count=2;

    void CreateHero(int );
    void DrawObject();
    void move(SDL_Keycode key);
    void CreatePolice();
    

};
