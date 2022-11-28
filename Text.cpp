#include "Text.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <sstream>

 Text::Text(SDL_Renderer *renderer,
    const string &fontPath, 
    int fontSize, 
    const string &text, 
    const SDL_Color &color)
    {
        textTexture = loadFont(renderer, fontPath, fontSize,text, color);
        SDL_QueryTexture(textTexture, nullptr,nullptr, &textRect.w,&textRect.h);
    }


void Text::display(int x, int y, SDL_Renderer *renderer)
const 
{
    textRect.x = x;
    textRect.y = y;
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer,
    const string &fontPath,
    int fontSize,
    const string &text, 
    const SDL_Color &color)
    {
        TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
        if(!font)
        {
            cerr<<"failed to load font\n";
        }
        auto text_surface = TTF_RenderText_Solid(font, text.c_str(), color);
        if(!text_surface)
        {
            cerr<< "failed to create text surface\n";
        }
        auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        if(!text_texture)
        {
            cerr<<"failed to create text texture\n";
        }
        SDL_FreeSurface(text_surface);
        return text_texture;

}

