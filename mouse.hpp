#include <SDL.h>
#include <SDL_image.h>
#include "Drawing.hpp"


class Mouse{
    public:
    // SDL_Texture *tex;
    SDL_Rect sprite = {62,28,249,272};
    SDL_Rect rect;
    SDL_Rect point;

    Mouse();

    void update();

    void draw();
};