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
        void operator +=(int x);
        void operator -=(int x);
        void displayScore(int, int,int);
        bool operator >(int x);


};