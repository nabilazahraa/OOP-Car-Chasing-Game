#include "Drawing.hpp"
#include "SprintCar.hpp"
using namespace std;

void SprintCar::CreateHero(int choice)
{
    //select option 
    //if 1,2,3 selected make herocar according to that

    if(choice ==1){
    
     //sportscar
    h = new heroCar(984,39,101,174);
    }
    else if(choice == 2)
    {
    //bike 
    h = new heroCar(1646,57,189,541) ;
    }
    //truck
    else if(choice == 3)
    {
    h = new heroCar(1337,0,219,410) ;
    }
    
}

void SprintCar::CreatePolice()
{
    p = new PoliceCar();
    if (count%2==0)
    {
        NormalCar *norm=new NormalCar();
        n.push_back(norm);
    }
    count++;
}

void SprintCar::DrawObject()
{
    h->Draw();
    p->Draw();
    for(int i=0;i<n.size();i++)
    {
        n[i]->Draw();
    }
}
void SprintCar::move(SDL_Keycode key)
{
    if(key == SDLK_LEFT || key == SDLK_RIGHT ||key == SDLK_UP ||key== SDLK_DOWN)
    {
    h->Drive(Drawing::gRenderer,Drawing::assets, key);
    }
    p->Drive(Drawing::gRenderer,Drawing::assets, key);
    for(int i=0;i<n.size();i++)
    {
        n[i]->Drive(Drawing::gRenderer,Drawing::assets, key);
    }
    
    // p->Drive(Drawing::gRenderer,Drawing::assets, key);
}
