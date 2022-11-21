#include "Drawing.hpp"
#include "SprintCar.hpp"
using namespace std;

void SprintCar::CreateObject()
{
    // h.Draw();
    

    //select option 
    //if 1,2,3 selected make herocar according to that

    // int choice;
    // cin >>choice;
    // if(choice ==1){
    h = new heroCar(0,0,143,262);
    // }
    
    //police car
    // p =  new policeCar;
}

void SprintCar::DrawObject()
{

    h->Draw();
}
void SprintCar::move(SDL_Keycode key)
{
     h->Drive(Drawing::gRenderer,Drawing::assets, key);
}