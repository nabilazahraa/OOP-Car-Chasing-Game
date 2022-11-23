
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Drawing.hpp"
using namespace std;


class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1500;
    const int SCREEN_HEIGHT = 810;
    string img = "smthng.gif";
    Mix_Music* gMusic = NULL;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    

public:



    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};