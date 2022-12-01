#include "Score.hpp"

//initializes score values
Score::Score()
{
    score = 0;
}


//special increase score by x = 1000 when police car destroyed
void Score::operator +=(int x)
{
    score +=x;
}

//decrease score when collision with normal car 
void Score::operator -=(int x)
{
    score -=x;
}

//prevent score from going below 0
bool Score::operator >(int x)
{
    return score>x;
}


//displays score on the screen 
void Score::displayScore(int x, int y,int w)
{
    string text = "Score: " + to_string(score);
    txt = new Text(Drawing::gRenderer, "./fonts/consolab.ttf",w, text, {255, 255 ,255});
    txt->display(x, y,Drawing::gRenderer);

}