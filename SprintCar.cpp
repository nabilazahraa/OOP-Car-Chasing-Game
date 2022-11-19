#include "Drawing.hpp"
#include "SprintCar.hpp"

void SprintCar::CreateObject()
{
    h.Draw();
    

    //select option 
    //if 1,2,3 selected make herocar according to that

    //police car
    // p =  new policeCar;
}

void SprintCar::DrawObject()
{

    h.Draw();
}
void SprintCar::move(SDL_Keycode key)
{
     h.Drive(Drawing::gRenderer,Drawing::assets, key);
}