#include <SDL.h>
#include <SDL_image.h>
#include "Drawing.hpp"


class Mouse{
    private:
        SDL_Rect sprite = {3204,14,128,139};
        SDL_Rect rect;
        SDL_Rect point;
    public:
        Mouse();
        void update();
        void draw();
};