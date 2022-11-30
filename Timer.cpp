#include "Timer.hpp"

//Initialize timer values
Timer::Timer()
{
    //Initialize the variables
    mStartTicks = 0;

    mStarted = false;

}

//start timer
void Timer::start()
{
    //Start the timer
    mStarted = true;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
}

//stop timer
void Timer::stop()
{
    //Stop the timer
    mStarted = false;

    //Clear tick variables
    mStartTicks = 0;
}

//we can overload maybe
Uint32 Timer::getTicks()
{
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

//check if timer is running
bool Timer::isStarted()
{
    return mStarted;
}

//display timer on screen
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