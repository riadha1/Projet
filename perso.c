#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
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
	p->posScreen.y=500;
	p->posSprite.x=0;
	p->posSprite.y=0;
	p->posSprite.h =37 ;
	p->posSprite.w =50;
	p->Signal=0;
	p->Signalb=0;
	p->isJump = 0;
	p->col = 1;
	p->speed = 0;
	p->ground = p->posScreen.y;
	p->frame = 0;
	p->frameb = 5;
}
void afficherPerso(perso p,SDL_Surface* screen)
{
	SDL_BlitSurface(p.sprite,&(p.posSprite),screen,&(p.posScreen));

}

void deplacerPerso(perso *p){
		
	if(((p->Signal == 1)||(p->Signalb == 1))&&(p->speed < 10)){
			p->speed+= 0.15;
		}
	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->speed > 0)){
		p->speed-=  0.75;
	}
	
	if(p->speed <= 0){
		p->speed = 0;
	}

	(p->posScreen.x)+= p->speed * p->direction;
	if (p->posScreen.x <= 0)
		p->posScreen.x = 0;
	if (p->posScreen.x >= 1200)
		p->posScreen.x = 1200;

}

void animerPerso(perso *p){
	if((p->direction == 1)&&(p->Signal == 1)){
		
		p->posSprite.x=(p->frame)*50;
		p->posSprite.y=1*37;
		p->posSprite.h=37;
		p->posSprite.w=50;
		p->frame++;
	}
	if((p->Signalb == 1)&&(p->direction == -1)){
		
		p->posSprite.x=(p->frameb)*50;
		p->posSprite.y=3*37;
		p->posSprite.h=37;
		p->posSprite.w=50;
		p->frameb--;

	}	

	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->isJump == 0)){
	  	p->posSprite.x=0;
		p->posSprite.y=0;
		p->posSprite.h=37;
		p->posSprite.w=50;
			}
	if((p->isJump == 1)&&(p->direction == 1))
	{
		p->posSprite.x=0;
		p->posSprite.y=2*37;
		p->posSprite.h=37;
		p->posSprite.w=50;	
	}
	if((p->isJump == 1)&&(p->direction == -1))
	{
		p->posSprite.x=50;
		p->posSprite.y=2*37;
		p->posSprite.h=37;
		p->posSprite.w=50;	
	}



}

void saut(perso *p){
	int y;
	int Amp = -300;
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
	p->posScreen.y = (int) y + p->ground;
}
