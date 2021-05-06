#ifndef back_H_INCLUDED
#define back_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct background
	{
        SDL_Surface *image;
        SDL_Rect camera,camera2,camerasolo;
       // SDL_Rect cam[2];
        Mix_Music *music;
    }background;

void initBack(background * b, int x,int y);
void aficherBack(background b, SDL_Surface * screen,int x,int y,int np);
void scrollingsolo (background * b, int direction, int pasAvancement);
void scrolling (background * b, int direction, int pasAvancement); 
void scrolling2 (background * b, int direction, int pasAvancement);



#endif // DS_H_INCLUDED
