#include <SDL.h>
#include <iostream>
#include "Text.hpp"
#include "Drawing.hpp"
#pragma once

class Timer
{
    public:
        //Initializes variables
        Timer();
    
        //The various clock actions
        void start();
        void stop();
        // void pause();
        // void unpause();

        //Gets the timer's time
        Uint32 getTicks();

        //Checks the status of the timer
        bool isStarted();
        // bool isPaused();
        void display();

    private:
        //The clock time when the timer started
        Uint32 mStartTicks;
        
        //The ticks stored when the timer was paused
        Uint32 mPausedTicks;
        Text* time;
        //The timer status
        bool mPaused;
        bool mStarted;
};