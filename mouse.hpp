#include <SDL.h>
#include <iostream>
#include "game.hpp"
using namespace std;

class Mouse{
    public:
    SDL_Texture *tex;
    SDL_Rect rect;
    SDL_Rect point;

    Mouse();

    void update();

    void draw();
};