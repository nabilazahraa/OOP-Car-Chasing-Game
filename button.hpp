#include <SDL.h>
#include <SDL_image.h>
#include "mouse.hpp"
#include "Drawing.hpp"
using namespace std;

class button{

private:
    SDL_Rect rect;
    SDL_Rect sprite;
    bool selected = false;

public: 
    button();
    virtual ~button();

    void update(Mouse&);    
    void draw(int x1, int y1, int w1, int h1,  int xr, int yr, int wr, int hr);

    bool handleEvent(SDL_Event* e);
};
