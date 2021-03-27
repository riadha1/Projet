#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "lot3.h"

SDL_Rect MAJminimap(SDL_Rect posmc,int resize)
{
  posmcABS.x=posmc.x+cam.x;
  posmcABS.y=posmc.y+cam.y;
  posminimc.x=posmcABS.x*resize/100;
  posminimc.y=posmcABS.y*resize/100;
}
void initmap(minimap *m)
{
  m.minimg=IMG_Load(.png);
  m.posminimap=int;
  m.minimc=IMG_Load(.png);
  m.posminimc=int;
}
void displaymap(minimap m,SDL_Surface *screen)
{
  SDL_BlitSurface(m.minimg,NULL,screen,&minimap.posminimap);
  SDL_BlitSurface(m.minimc,NULL,screen,&minimap.posminimc);
}
void freeminimap(minimap *m)
{
  SDL_FreeSurface(m.minimg);
  SDL_FreeSurface(m.minimc);
}
void displaytime(int *time)
{

}
int collisionMC(character c, SDL_Surface *mask)
{

}
