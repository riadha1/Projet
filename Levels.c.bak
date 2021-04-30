#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "LevelsHeader.h"
#include "Entite.h"
#include "perso.h"



void initLevel(int n){
  switch(n){
    case 1:
    //Level1(n);
    Demo(n);
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
  }
}

void Level1(int n){
  int Nbe = 1;
  int colEnt = 0;
  Ennemi e[10];
  //Init functions
  //initGlobalEnnemi(Nbe, e, n);
  initEnnemi(e);

//Init SDL
  if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        //printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
    	}

  SDL_Surface *screen;
	SDL_Event event;
	perso p;
	int quit=0;
	int Jump = 0;
	int right = 0;
	int left = 0;

	screen = SDL_SetVideoMode( 1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
  if( screen == NULL )
    	{
        //printf( "Can't set video mode: %s\n", SDL_GetError( ) );
    	}

init(&p,1);

//Main while cycle
	while(quit == 0)
  	{
  		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
  		afficherPerso(p, screen);
      afficherEnnemi(e, screen);
      animerEnnemi(e);
      deplacer(e);
      colEnt = collisionBB(p, e);
    //Event cycle
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
      		{
				case SDL_QUIT:
        		{
         				quit = 1;
				}
				break;
				case SDL_KEYDOWN:
    		if(event.key.keysym.sym == SDLK_RIGHT){
          p.Signal = 1;
          p.direction = 1;
					//right = 1;
          //printf("right\n");
    			}
    		if(event.key.keysym.sym == SDLK_LEFT){
          p.Signal = 1;
          p.direction = -1;
					//left = 1;
          //printf("left\n");
        	}
          if(event.key.keysym.sym == SDLK_UP){
            	p.isJump = 1;
            }
    		break;
    		case SDL_KEYUP:
    			if(event.key.keysym.sym == SDLK_UP){
            	Jump = 0;
            }
					if((event.key.keysym.sym == SDLK_LEFT)||(event.key.keysym.sym == SDLK_RIGHT)){
							p.Signal = 0;
						}
    		break;
				default:
				break;
			}
		}
		saut(&p);
    	deplacerPerso(&p);
    	SDL_Flip(screen);
      SDL_Delay(10);
	}
    //outside of the menu cycle
    SDL_FreeSurface(p.sprite);
    Liberer(e);
    SDL_Quit();
}

void Demo(int n){
  int Nbe = 1;
  int colEnt = 0;
  Ennemi e;
  Ennemi eAI;
  //Init functions
  //initGlobalEnnemi(Nbe, e, n);
  initEnnemiSimple(&e, 1);
  initEnnemiSimple(&eAI, 2);

//Init SDL
  if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        //printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
    	}

  SDL_Surface *screen;
	SDL_Event event;
	perso p;
	int quit=0;
	int Jump = 0;
	int right = 0;
	int left = 0;

	screen = SDL_SetVideoMode( 1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
  if( screen == NULL )
    	{
        //printf( "Can't set video mode: %s\n", SDL_GetError( ) );
    	}

init(&p,1);

//Main while cycle
	while(quit == 0)
  	{
  		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
  		afficherPerso(p, screen);
      afficherEnnemiSimple(e, screen);
      afficherEnnemiSimple(eAI, screen);
      animerEnnemiSimple(&e);
      animerEnnemiSimple(&eAI);
      deplacerSimple(&e);
      deplacerAI(&eAI, p);
      colEnt = collisionBBSimple(p, e);
    //Event cycle
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
      		{
				case SDL_QUIT:
        		{
         				quit = 1;
				}
				break;
				case SDL_KEYDOWN:
    		if(event.key.keysym.sym == SDLK_RIGHT){
          p.Signal = 1;
          p.direction = 1;
					//right = 1;
          //printf("right\n");
    			}
    		if(event.key.keysym.sym == SDLK_LEFT){
          p.Signal = 1;
          p.direction = -1;
					//left = 1;
          //printf("left\n");
        	}
          if(event.key.keysym.sym == SDLK_UP){
            	p.isJump = 1;
            }
    		break;
    		case SDL_KEYUP:
    			if(event.key.keysym.sym == SDLK_UP){
            	Jump = 0;
            }
					if((event.key.keysym.sym == SDLK_LEFT)||(event.key.keysym.sym == SDLK_RIGHT)){
							p.Signal = 0;
						}
    		break;
				default:
				break;
			}
		}
		saut(&p);
    	deplacerPerso(&p);
    	SDL_Flip(screen);
      SDL_Delay(10);
	}
    //outside of the menu cycle
    SDL_FreeSurface(p.sprite);
    LibererSimple(e);
    LibererSimple(eAI);
    SDL_Quit();
}
