#include <SDL.h>
#include <iostream>
#include "Text.hpp"
#include "Drawing.hpp"
#pragma once

class Timer
{
    private:
        //The clock time when the timer started
        Uint32 mStartTicks;
        //The ticks stored when the timer was paused
        Text* time;
        //The timer status
        bool mStarted;

    public:
        //Initializes variables
        Timer();

        //The various clock actions
        void start();
        void stop();

        //Gets the timer's time
        Uint32 getTicks();

        //Checks the status of the timer
        bool isStarted();
       
       //display time
        void display();
};