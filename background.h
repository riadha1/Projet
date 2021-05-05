#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
/*
typedef struct {

	SDL_Surface *back_Img;
	SDL_Surface *back_Img2;
	SDL_Rect back_Pos;

}Background;


void  loadBackground(Background *Back);
void initBackground(Background *Back);
void freeBackground(Background *Back);
void blitBackground(Background *Back,SDL_Surface *screen);*/
typedef struct {
	SDL_Surface *background_Img;
        SDL_Rect backgroundPos;
        SDL_Rect camera;
        SDL_Rect backgroundPos2;
        SDL_Rect camera2;
    
}background;
void  loadBackground(background *Back);
void initialiser_Background(background *Backg);
void blitbackground(background *Backg,SDL_Surface *screen);
void blitbackground2(background *Backg,SDL_Surface *screen);
void scrolling(background *backg,int *b,int c);
void freeBackground(background *Back);
int colbackgroundleft(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1);
int colbackgroundRight(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1);
int colbackgroundDown(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1);
int colbackgroundUp(SDL_Surface* Backgroundmasque,SDL_Rect positionhero1);
#endif
