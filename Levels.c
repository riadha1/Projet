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
#include "background.h"




void initLevel(int n,int np){
  switch(n){
    case 1:
    //Level1(n);
    Demo(n,np);
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
  }
}

void Demo(int n,int np){

  SDL_Surface *screen;
  int Nbe = 1;
  int colEnt = 0;
  Ennemi e;
  Ennemi eAI;
  //bg
    background b;
    int direction=0,vitesse=0,direction2=0,vitesse2=0;
    int resx=1366,resy=768;
  //Init functions
    
  initEnnemiSimple(&e, 1);
  initEnnemiSimple(&eAI, 2);

//Init SDL
  if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        //printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
    	}
// init audio 
      if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
        printf("%s",Mix_GetError());

	SDL_Event event;
	perso p,p2;
	int quit=0;
	int Jump = 0;
	int right = 0;
	int left = 0;

	screen = SDL_SetVideoMode( 1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
  if( screen == NULL )
    	{
        //printf( "Can't set video mode: %s\n", SDL_GetError( ) );
    	}
initBack(&b,resx,resy);
init(&p,1);
if(np==2)
{
  init(&p2,2);
  p2.posScreen.x=700;
}
SDL_EnableKeyRepeat(30,30);
//Main while cycle
	while(quit == 0)
  	{
  		aficherBack(b,screen,resx,resy,np);
      afficherPerso(p, screen);
      if (np == 2){
      afficherPerso(p2, screen);
      }
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
        if(event.key.keysym.sym == SDLK_d){
            p2.Signal = 1;
            p2.direction = 1;
            //bg
                    direction2='R';
                    vitesse2++;
        }
        if(event.key.keysym.sym == SDLK_q){
            p2.Signalb = 1;
            p2.direction = -1;
            //bg
            direction2='L';
            vitesse2++;

        }
        if(event.key.keysym.sym == SDLK_z){
          p2.isJump = 1;
        }
    		if(event.key.keysym.sym == SDLK_RIGHT){
              p.Signal = 1;
              p.direction = 1;
              //bg
                direction='R';
                vitesse++;
              
    		}
    		if(event.key.keysym.sym == SDLK_LEFT){
                  p.Signalb = 1;
                  p.direction = -1;
                  //bg
                    direction='L';
                    vitesse++;
                  
            }
            if(event.key.keysym.sym == SDLK_UP){
            	p.isJump = 1;
             
            }
            if(event.key.keysym.sym == SDLK_DOWN){
              
            }
    		break;
    		case SDL_KEYUP:
              if(event.key.keysym.sym == SDLK_d){
                p2.Signal = 0;
                //bg
                vitesse2=0;
                    
                    
              }
              if(event.key.keysym.sym == SDLK_q){
                  p2.Signalb = 0; 
                  //bg
                  vitesse2=0;
                    
              }
    			   if(event.key.keysym.sym == SDLK_RIGHT){
                  p.Signal = 0;
                  //bg
                  vitesse=0;
                }
            if(event.key.keysym.sym == SDLK_LEFT){
                   p.Signalb = 0;
                   //bg
                   vitesse=0;
                 }
            


    		break;
				default:
				break;
			}
		}
		
      
      if( np == 1){
        if (p.posScreen.x<=1366/2)
        deplacerPerso(&p);
       else 
        scrollingsolo(&b,direction,vitesse);
    }
      
      if ( np == 2){
        if(p.posScreen.x>=1366/4)
        scrolling(&b,direction,vitesse);  
      else
        deplacerPerso(&p);
      if(p2.posScreen.x>=1366*3/4)
        scrolling2(&b,direction2,vitesse2);
      else
        deplacerPerso(&p2);
        }
      
        animerPerso(&p);
      if (np == 2){
        animerPerso(&p2);
      } 
       if (p.frame >= 5)
        p.frame = 0;
      if (p.frameb <= 0)
        p.frameb = 5;
      if (np== 2)
      {
          if (p2.frame >= 5)
        p2.frame = 0;
      if (p2.frameb <= 0)
        p2.frameb = 5;
      }

      saut(&p);
      if (np == 2)
      {
        saut(&p2);
      }
    
    	
    	
      
     
    	SDL_Flip(screen);
      	SDL_Delay(10);
	}
    //outside of the menu cycle
    SDL_FreeSurface(p.sprite);
    LibererSimple(e);
    LibererSimple(eAI);
    SDL_Quit();
}
