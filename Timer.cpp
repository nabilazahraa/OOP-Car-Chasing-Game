#include "Timer.hpp"


Timer::Timer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;

}

void Timer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Timer::stop()
{
    
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    // mPaused = false;

    //Clear tick variables
    mStartTicks = 0;
    // mPausedTicks = 0;
    
}

//we can overload maybe
Uint32 Timer::getTicks()
{
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        // if( mPaused )
        // {
        //     //Return the number of ticks when the timer was paused
        //     time = mPausedTicks;
        // }
        // else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool Timer::isStarted()
{
    //Timer is running and paused or unpaused
    return mStarted;
}

void Timer::display()
{
    string secs;
    int s= (getTicks() / 1000 )%60;
    if(s<10)
    {
        secs = "0" + to_string(s);
    }
    else
    {
        secs = to_string(s);
    }

    string mins;
    mins = "0" + to_string(getTicks()/60000);
    string txt = "Time: " + mins+":" +secs; 
    time = new Text(Drawing::gRenderer, "./fonts/consolab.ttf",20, txt, {255, 255 ,255});
    time->display(1300,750,Drawing::gRenderer);
}