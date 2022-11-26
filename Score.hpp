#include <iostream>
#include <SDL.h>

class Score
{
    int score;

    public:
    //operator overloading to increase score
    // void operator ++()

    void decreaseScore();
    void displayScore();


};