#include <iostream>
#include <SDL.h>
#include "mouse.hpp"
#include "Drawing.hpp"

class button{
public: 
    SDL_Texture *tex;
    SDL_Rect srect, drect;
    SDL_Rect sprite = {};
    bool isSelected = false;

    button();
    virtual ~button();

    void update(Mouse&);   
    void draw();
};
