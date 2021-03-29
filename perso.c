#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

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
	p->posScreen.y=100;
	p->posSprite.x=0;
	p->posSprite.y=0;
	p->Signal=0;
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
				(p->posScreen.x)+= 20 * p->Signal * p->direction;
               	printf("move\n");
    		}


    	
    
  

 

void animerPerso(perso *p)
{



}
void saut(perso *p)
{


    
}
