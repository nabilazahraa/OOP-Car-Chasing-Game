#include "Score.hpp"

Score::Score()
{
    score = 0;
}

//increase score while moving
void Score::operator ++()
{
    ++score;
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

void Score::displayScore()
{
    string text = "Score: " + to_string(score);
    txt = new Text(Drawing::gRenderer, "./fonts/consolab.ttf",20, text, {255, 255 ,255});
    txt->display(90,10,Drawing::gRenderer);

}