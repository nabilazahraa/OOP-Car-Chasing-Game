#include "game.hpp"
#include "SprintCar.hpp"
#include "Drawing.hpp"
#include "button.hpp"
#include "Fire.hpp"
#include <SDL_Mixer.h>
#include <list>
#include <vector>
#include "Health.hpp"
#include "Text.hpp"
#include "Timer.hpp"
#include <string>
#include <sstream>
#include "finish.hpp"

using namespace std;

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;


bool Game::init()
{
	//Initialization flag
	bool success = true;
	 if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }

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
	
	Drawing::assets = loadTexture("./assets/spritesheet.png");
    gTexture = loadTexture(img);
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	gMusic = Mix_LoadMUS( "./sounds/tokyo.wav" );
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

			mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}


void Game::run()
{
	bool quit = false;
	SDL_Event e;

	Timer timer;

	SprintCar sprintcar;

	int scrollingOffset = 0;

	Mouse m;
	
	button play;
	button rules;
	button exit;
	button back;
	button car1;
	button car2;
	button car3;
	button replay;

	// Health life;
	Text text(Drawing::gRenderer, "./fonts/MATURASC.TTF",100, "Sprint Car Derby", {255, 255 ,255 ,255});

	finishLine line;
   
	
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
				//move the car using arrow keys	
				sprintcar.move(e.key.keysym.sym);
			}
			//click on buttons
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				//start game
				if(img == "./assets/smthng.gif")
				{
					if(play.handleEvent(&e) ==true)
					{
						img ="./assets/choose.gif";
						loadMedia();
					}

					//show rules screen
					if(rules.handleEvent(&e) ==true)
					{
						img = "./assets/rules.png";
						loadMedia();
					}

				}
				if(img =="./assets/smthng.gif" || img =="./assets/GameWon.png" || img == "./assets/gamelost.png")
				{
					//exit game 
					if(exit.handleEvent(&e) ==true)
					{
						quit = true;
						
					}
				}
				if(img == "./assets/rules.png")
				{
					//go back from rules screen
					if(back.handleEvent(&e) ==true)
					{
						img = "./assets/smthng.gif";
						
						loadMedia();
						
					}
				}
				//choosing cars
				if(img =="./assets/choose.gif")
				{
					if(car1.handleEvent(&e) ==true)
					{
						img = "./assets/road.png";
						loadMedia();
						sprintcar.CreateHero(1);
						timer.start();
						
					}
					else if(car2.handleEvent(&e) ==true)
					{
						img = "./assets/road.png";
						sprintcar.CreateHero(2);
						loadMedia();
						timer.start();
					}
					else if(car3.handleEvent(&e) ==true)
					{
						img = "./assets/road.png";
						sprintcar.CreateHero(3);
						loadMedia();
						timer.start();
					}
				}

				if(replay.handleEvent(&e) ==true)
				{
					//go to main screen again
					img ="./assets/choose.gif";
					loadMedia();
				}

			}
			
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); //Draws background to renderer
		
		//***********************draw the objects here********************//
		
		if(img =="./assets/road.png")
		{
			//background scrolling
			scrollingOffset += 30;
			if( scrollingOffset > SCREEN_HEIGHT)
			{
				scrollingOffset = 0;
			}
			
			SDL_Rect renderQuad = { 0, scrollingOffset, SCREEN_WIDTH, SCREEN_HEIGHT };
			SDL_RenderCopy( Drawing::gRenderer, gTexture, NULL, &renderQuad);
			renderQuad = { 0, scrollingOffset - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
			SDL_RenderCopy( Drawing::gRenderer, gTexture, NULL, &renderQuad );


			//display timer
			timer.display();

			if(timer.getTicks()>= 90000)
			{
				timer.stop();
				img = "./assets/GameWon.png"; //game won screen
				loadMedia();
			}

			//game is lost when lives are =0
			if(sprintcar.getLife()==0)
			{
				
				img = "./assets/gamelost.png";
				loadMedia();
			}

			sprintcar.CreateNormal();

			//draw chosencar 
			sprintcar.DrawObject();

			if(timer.getTicks()<=86000)
			{
				sprintcar.DrawCars();
				sprintcar.moveCars();	
			}
			//draw finish line when timer about to end
			else if(timer.getTicks() >= 87000)
			{
				line.draw();
				line.move();
			}
		}

		//play music for all screen
		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			Mix_PlayMusic( gMusic, -1 );
		}

		if(img =="./assets/smthng.gif")
		{
			text.display(50,50,Drawing::gRenderer);
			play.draw(25,24,189,70, 180, 500, 250, 70);
			rules.draw(25,111,189,71,180,580,250,70);
			exit.draw(25,206,189,71, 180, 660, 250,70);
		}

		if(img == "./assets/rules.png")
		{
			back.draw(25,301,189,70,20,10,150,70);
		}
		
		if(img == "./assets/choose.gif")
		{
			car1.draw(278,16,206,198, 200,300,300,300); //ferrari button
			car2.draw(521,15,206,197, 600,300,300,300); //ducati button
			car3.draw(415,251,206,197,1000,300,300,300); //monster truck button
		}

		if(img == "./assets/GameWon.png")
		{
			replay.draw(25,389,189,70, 180, 500, 250, 70);
			exit.draw(25,206,189,71,180,580,250,70);
			sprintcar.DisplayScore();
		}
		if(img == "./assets/gamelost.png")
		{
			replay.draw(25,389,189,70, 180, 500, 250, 70);
			exit.draw(25,206,189,71,180,580,250,70);
			sprintcar.DisplayScore();
		}
		
		//draw mouse
		m.draw();

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
		
}