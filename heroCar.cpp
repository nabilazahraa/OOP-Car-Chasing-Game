#include "heroCar.hpp"
#include "Drawing.hpp"

//Draw the car and its attributes on the screen 
void heroCar::Draw(){

    //draw bullets
    // for(int i=0;i<b.size();i++)
    // {
    //     b[i]->Draw();
    //     b[i]->ShootBullets();
    // }

   
    //draw health
    life.Draw();
    //draw score
    score.displayScore(90,10,20);
    //increase score 
    ++score;


    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    

}

//initializes heroCar according to the sprite values
heroCar::heroCar(int x, int y, int w, int h )
{
    setmoverRect(390,500, 100,120);
    setRect(x,y,w,h);
   
}

//Drive car using arrow keys
void heroCar::DriveHero(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key)
{
    
    // if (key == SDLK_UP)
    // {
    //     if(moverRect.y<0) 
    //         moverRect.y = 800;
    //         //not move out of screen in y axis
    //      moverRect.y-=30;
    // }
    // else if (key == SDLK_DOWN ) {
    //     if(moverRect.y<700) //not move out of screen in y axis
    //     moverRect.y+=30;
    // }

    if (key==SDLK_RIGHT) {
        if(moverRect.x<1100) //not move out of screen in x axis
        moverRect.x+=35;

    }
    else if (key == SDLK_LEFT) {
        if(moverRect.x>300) //not move out of screen in x axis
        moverRect.x-=35;
    }
    else if(key== SDLK_SPACE){
        // if(fram%2==0)
        {
            Bullets *b1=new Bullets(moverRect.x,moverRect.y);
            b.push_back(b1);
            
        }
    }
    // fram++;

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void heroCar::IncreaseScore()
{
    score+=1000;
}
//display hero car score
void heroCar::DisplayScore()
{
    score.displayScore(500,700,100); 
}

void heroCar::DrawBullets(car* p,car*h)
{
    for(int i=0;i<b.size();i++)
    {
        b[i]->Draw();
        b[i]->ShootBullets();
        if(b[i]->gone==true)
        {
            b.erase(b.begin()+i); //DELETES THE BULLETS OBJECT AS SOON AS IT LEAVES SCREEN.
        }
    }
}

void heroCar::DecreaseHealth()
{
    --life;
}

int heroCar::getLife()
{
    return life.getlives();
}


void heroCar::DecreaseScore()
{
    if(score>0)
    {
        score-=100;
    }
}
heroCar::~heroCar()
{
    for(int i=0;i<b.size();i++)
    {
        delete b[i];
    }
    b.clear();
}
