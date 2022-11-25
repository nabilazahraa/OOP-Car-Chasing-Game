#include "game.hpp"
#include "SprintCar.hpp"
#include "Drawing.hpp"
#include "button.hpp"
#include "Fire.hpp"
#include <SDL_Mixer.h>
#include <list>
#include <vector>
#include "Health.hpp"
using namespace std;

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;


bool Game::init()
{
	//Initialization flag
	bool success = true;

	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		
		//Create window
		gWindow = SDL_CreateWindow( "Sprint Car Derby", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("spritesheet.png");
    gTexture = loadTexture(img);
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	gMusic = Mix_LoadMUS( "Animals.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;

	Mix_FreeMusic(gMusic);
	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	SprintCar sprintcar;
	Mouse m;
	
	button play;
	button rules;
	button exit;

	button car1;
	button car2;
	button car3;

	Fire *fr = new Fire();
	Health h;

	
	while( !quit )
	{
		m.update();
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			
			//User requests quit
		
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_KEYDOWN)
			{
				if(e.key.keysym.sym == SDLK_SPACE)
				{
					fr->alive = true;
					SDL_Rect moverRect = sprintcar.h->getRect();
					fr->update(moverRect);
				} 
					
				sprintcar.move(e.key.keysym.sym);
				
				
			}
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				if(play.handleEvent(&e) ==true)
				{
				img ="choose.gif";
				// img =="./assets/road.png";

				loadMedia();
				}
				if(exit.handleEvent(&e) ==true)
				{
					close();
					quit = true;
				}
				if(car1.handleEvent(&e) ==true)
				{
					img = "./assets/road.png";
					sprintcar.CreateObject(1);
					loadMedia();
				}
				if(car2.handleEvent(&e) ==true)
				{
					img = "./assets/road.png";
					sprintcar.CreateObject(2);
					loadMedia();
				}
				if(car3.handleEvent(&e) ==true)
				{
					img = "./assets/road.png";
					sprintcar.CreateObject(3);
					loadMedia();
				}
			}
			
			
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		if(img =="./assets/road.png")
		{
		sprintcar.DrawObject();
		
		//firing 
		fr->Draw();
		fr->Shoot();

		//health
		h.Draw();

		Mix_PauseMusic();
		}

		
			if( Mix_PlayingMusic() == 0 )
			{
				//Play the music
				Mix_PlayMusic( gMusic, -1 );
			}
		if(img =="smthng.gif")
		{
		play.draw(25,24,189,70, 180, 500, 250, 70);
		rules.draw(25,111,189,71,180,580,250,70);
		exit.draw(25,206,189,71, 180, 660, 250,70);

		//back{25,301,189,70}
		//replay {25,389,189,70}

		//ferrari {278,16,206,198}
		//ducati {521,15,206,197}
		//monster truck {415,251,206,197}
		}
		if(img == "choose.gif")
		{
			car1.draw(278,16,206,198, 200,300,300,300);
			car2.draw(521,15,206,197, 600,300,300,300);
			car3.draw(415,251,206,197,1000,300,300,300);
		}
		
		m.draw();

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}

