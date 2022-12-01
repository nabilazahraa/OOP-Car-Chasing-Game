#include "Drawing.hpp"
#include "SprintCar.hpp"
using namespace std;

void SprintCar::CreateHero(int choice)
{
    //select option 
    //if 1,2,3 selected make herocar according to that

    if(choice ==1)
    {
         //ferrari
        h = new heroCar(984,39,101,174);
    }
    else if(choice == 2)
    {
        //ducati 
        h = new heroCar(1646,57,189,541) ;
    }
    
    else if(choice == 3)
    {
        //monster truck
        h = new heroCar(1337,0,219,410) ;
    }

    //create police car
    p = new PoliceCar();
    
    
}

//create normal car 
void SprintCar::CreateNormal()
{
    if (count<2) //only 2 cars should be on the screen
    {
        if(count ==0)
        {
            NormalCar *norm=new NormalCar(1);
            n.push_back(norm);    
        }
        else
        {   
             NormalCar *norm=new NormalCar(2);
             n.push_back(norm);
        }
        
    }
    count++;
}

//draw sprint car objects herocar, normal car, police car
void SprintCar::DrawObject()
{
    h->Draw();
    h->DrawBullets(p,h);
    

}

//draw normal car and police car
void SprintCar::DrawCars()
{
    p->DrawBullets(h); //draw bullets of police car
    p->Draw();

    //normal car 
    for(int i=0;i<n.size();i++)
    {
        n[i]->Draw();
    }
}

//move and shoot bullets of hero car
void SprintCar::move(SDL_Keycode key)
{
    if(key == SDLK_LEFT || key == SDLK_RIGHT ||key == SDLK_UP ||key== SDLK_DOWN ||key == SDLK_SPACE)
    {
        h->DriveHero(Drawing::gRenderer,Drawing::assets, key);
    }
    
}

//move police car and normal car
void SprintCar::moveCars()
{
    p->DriveCar();
    SDL_Rect police = p->getmoverRect();
    int direction = p->getDirection();
    for(int i=0;i<n.size();i++)
    {
        n[i]->DriveNormalCar(h,police, direction);
    }
}

//returns life of hero car
int SprintCar::getLife()
{
    return h->getLife();
}

//displays score of hero car
void SprintCar::DisplayScore()
{
    h->DisplayScore();
}

//destructor for sprintcar
SprintCar::~SprintCar()
{
    for(int i=0;i<n.size();i++)
    {
        delete n[i];
    }
    n.clear();
}
