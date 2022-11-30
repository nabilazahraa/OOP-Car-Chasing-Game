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

    private:
        car *h; //herocar

        car *p; //police car

        vector<car*>n; //normal car
        int count=0;
    public:
        void CreateHero(int );
        void DrawObject();
        void move(SDL_Keycode key);
        void moveCars();
        void CreateNormal();   
        void score(); 
        void DrawCars();
        void DisplayScore();
        int getLife();
        ~SprintCar();
};  

