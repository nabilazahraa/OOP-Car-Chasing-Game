// #include "button.hpp"

<<<<<<< HEAD
button::button()
{
    //static SDL_Texture *t = IMG_loadTexture(gWindow, "spritesheet")
    //tex = t;
    // srect.h = 100; //sprite sheet value
    // srect.w = 400;
    // srect.x = 0;
=======
// button::button()
// {
//     static SDL_Texture *t = IMG_loadTexture(gRenderer, "spritesheet")
//     tex = t;
//     srect.h = 100; //sprite sheet value
//     srect.w = 400;
//     srect.x = 0;
>>>>>>> f94fd06ca8cc937f9ad6bbc394a9bc990ee546c8

//     drect.h = 75;
//     drect.w = 300;

// }

// button::~button()
// {

// }

<<<<<<< HEAD
void button::update(Mouse& mouse)
{
    if(SDL_HasIntersection(&drect, &mouse.point))
    {
        isSelected = true;
        //srect.x = 400;

    }
    else{
        isSelected = false;
        //srect.x = 0;
    }
}

void button::draw()
{
    srect = sprite;
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srect, &drect);
}
=======
// void button::update(Mouse& mouse)
// {
//     if(SDL_HasIntersection(&drect, &mouse.point))
//     {
//         isSelected = true;
//         srect.x = 400;

//     }
//     else{
//         isSelected = false;
//         srect.x = 0;
//     }
// }

// void button::draw()
// {
//     SDL_RenderCopy(gRenderer,tex,&srect,&drect);
// }
>>>>>>> f94fd06ca8cc937f9ad6bbc394a9bc990ee546c8
