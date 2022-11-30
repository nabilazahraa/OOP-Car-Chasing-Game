#include <iostream>
#include <SDL.h>
#include "Drawing.hpp"
#pragma once

class finishLine
{
    private:
    SDL_Rect srcRect= {2254,135,481,141};
    SDL_Rect moverRect = {250 ,100,1000,300};

    public:
    void draw();
    void move();
};