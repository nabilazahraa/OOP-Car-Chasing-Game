#include <SDL.h>
#include <string.h>
#include <iostream>
#include "Drawing.hpp"
#include <SDL_ttf.h>
#pragma once
using namespace std;

class Text
{
    private:
        SDL_Texture* textTexture = nullptr;
        mutable SDL_Rect textRect;

    public:
        Text(SDL_Renderer *renderer, const string &fontPath, int fontSize, const string &text, const SDL_Color &color);
        void display(int x, int y, SDL_Renderer * renderer)const;
        static SDL_Texture* loadFont(SDL_Renderer * renderer,const string &fontPath,int fontSize,const string &text, const SDL_Color &color);
    // ~Text();


};