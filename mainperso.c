#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"



int main(int argc, char** argv)
{	 
//////////////////////////////////////// 
	if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}
///////////////////////////////////////////////////////////////////
    	SDL_Surface *screen;
		  SDL_Event event;
		  perso p;
		  int quit=0;
		  int Jump = 0;
		  //int Col = 1;
		  //int VarX = 0;

	
 //////////////////////////////////////
		screen = SDL_SetVideoMode( 1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    	if( screen == NULL )
    	{
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}
//////////////////////////////////////////////
    	init(&p,1);
///////////////////////////////////////////////	
	while(quit == 0)
  	{ 
  		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
  		afficherPerso(p,screen);
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
          
           
                printf("right\n");
                
    		}
    		if(event.key.keysym.sym == SDLK_LEFT){
                  p.Signal = 1;
                  p.direction = -1;
                printf("left\n");
    		
            }
            if(event.key.keysym.sym == SDLK_UP){
            	Jump = 1;
            }
    		break;
    		case SDL_KEYUP:
    			/*if(event.key.keysym.sym == SDLK_UP){
            	Jump = 0;
            }*/
    		    p.Signal = 0;
    		break;
				default:
				break;
			}
		}
		/*if(p.posScreen.y <= 100){
			Col == 1;
			p.posScreen.y = 100;
		}
   		if((Jump == 1)||(Col == 0)){
   			Col = 0;
   			VarX+=0.3;
   		}
   		if(Col == 1){
   			VarX = 0;
   		}
   		p.posScreen.y = ((-(VarX-3.162)*(VarX-3.162))+10);*/
		
    	deplacerPerso(&p);
    	
    	SDL_Flip(screen);
      SDL_Delay(10);
    	
	}
    //outside of the menu cycle
    SDL_FreeSurface(p.sprite);
    SDL_Quit();
    return EXIT_SUCCESS;
}
