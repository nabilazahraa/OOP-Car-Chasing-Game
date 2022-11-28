#include <iostream>
#include <SDL.h>
#include "Text.hpp"

class Score
{
    private:
        int score;
        Text* txt;
    public:
        Score();
    //operator overloading to increase score
        void operator +=(int x);
        void operator -=(int x);
        void operator ++();
        void displayScore();


};