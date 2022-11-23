// #include <SDL.h>
// #include "mouse.hpp"
// using namespace std;


<<<<<<< HEAD
Mouse::Mouse(){
        tex = IMG_loadTexture (gWindow, "cursor.jpg");
        rect.w = 25;
        rect.h = 25;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(false);
    }
=======
// Mouse::Mouse(){
//         tex = IMG_loadTexture (gRenderer, "cursor.jpg");
//         rect.w = 25;
//         rect.h = 25;
//         point.w = 1;
//         point.h = 1;
//         SDL_ShowCursor(false);
//     }
>>>>>>> f94fd06ca8cc937f9ad6bbc394a9bc990ee546c8

// void Mouse:: update(){
//         SDL_GetMouseTexture(&rect.x, &rect.y)
//         point.x = rect.x;
//         point.y = point.y;
//     }

<<<<<<< HEAD
void Mouse:: draw(){
        SSDL_RenderCopy(Drawing::gRenderer, Drawing::assets, NULL, &drect);
    }
=======
// void Mouse:: draw(){
//         SDL_RenderCopy(gRenderer, tex, NULL, &rect);
//     }
>>>>>>> f94fd06ca8cc937f9ad6bbc394a9bc990ee546c8
