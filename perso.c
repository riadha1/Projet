#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "perso.h"

int ClassPerso(){
	if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
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
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}

    	init(&p,1);

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
					right = 1;
          printf("right\n");
    			}
    		if(event.key.keysym.sym == SDLK_LEFT){
          p.Signal = 1;
          p.direction = -1;
					left = 1;
          printf("left\n");
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
    SDL_Quit();
    return EXIT_SUCCESS;
}

void init(perso* p,int numperso)
{
	p->num=numperso;
	p->sprite=IMG_Load("char.png");
    if( p->sprite == NULL )
        {
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        }
	p->direction=1;
  p->posScreen.x=0;
	p->posScreen.y=700;
	p->posSprite.x=0;
	p->posSprite.y=0;
	p->Signal=0;
	p->isJump = 0;
	p->col = 1;
	p->speed = 0;
	//p->posSprite.h=0;
	//p->posSprite.w=0;
	//p->velocity = 0;
}
void afficherPerso(perso p,SDL_Surface* screen)
{
	SDL_BlitSurface(p.sprite,NULL,screen,&(p.posScreen));

}
///////////////////////////////////////////////////////////////////////// right
void deplacerPerso(perso *p){
	if((p->Signal == 1)&&(p->speed < 20)){
		p->speed+= 0.3;
		printf("Inc\n");
	}
	if((p->Signal == 0)&&(p->speed > 0)){
		p->speed-=  0.75;
		printf("%f\n", p->speed);
		//printf("Dec\n");
	}
	if(p->speed < 0){
		p->speed = 0;
	}
				(p->posScreen.x)+= p->speed * p->direction;
}

void animerPerso(perso *p){
}

void saut(perso *p){
	int y;
	int Amp = -200;
	float delta = -4*Amp;
	float x = (sqrt(delta) / (2));
	if((p->isJump == 1)||(p->col == 0)){
		p->VarX ++;
		printf("Jump\n");
	}
	y = (int)((p->VarX - x)*(p->VarX - x) + Amp);
	if(y < 0){
		p->col = 0;
	}
	if(y >= 0){
		y = 0;
		p->VarX = 0;
		p->isJump = 0;
		p->col = 1;
	}
	p->posScreen.y = (int) y;
}
