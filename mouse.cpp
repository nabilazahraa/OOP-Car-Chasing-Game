#include <SDL.h>
#include "mouse.hpp"
using namespace std;


Mouse::Mouse(){
        tex = IMG_loadTexture (gWindow, "cursor.jpg");
        rect.w = 25;
        rect.h = 25;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(false);
    }

void Mouse:: update(){
        SDL_GetMouseTexture(&rect.x, &rect.y)
        point.x = rect.x;
        point.y = point.y;
    }

void Mouse:: draw(){
        SSDL_RenderCopy(Drawing::gRenderer, Drawing::assets, NULL, &drect);
    }