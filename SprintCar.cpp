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
    
     //sportscar
    // h = new heroCar(0,0,143,262);
    // }

    //bike 
    // h = new heroCar(84,57,189,541) ;

    //truck
    h = new heroCar(34,0,219,410) ;

    //police car

    p =  new PoliceCar;
}

void SprintCar::DrawObject()
{

    h->Draw();
    p->Draw();
}
void SprintCar::move(SDL_Keycode key)
{
     h->Drive(Drawing::gRenderer,Drawing::assets, key);
    p->Drive(Drawing::gRenderer,Drawing::assets, key);
}