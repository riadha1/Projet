#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "lot3.h"

void initmap(minimap *m)
{
  m->minibg=IMG_Load("resources minimap/minibg.png");
  m->posminimap.x=100;
  m->posminimap.y=200;
  m->minimc=IMG_Load("resources minimap/minichar.png");
}
SDL_Rect MAJminimap(perso p,minimap *m,int resize,SDL_Rect cam)
{
  /*posminimc.x=p.posScreen.x+m->posminimap.x;
  posminimc.y=p.posScreen.y+m->posminimap.y;*/
  SDL_Rect posmcABS,posminimc;
  posmcABS.x=p.posScreen.x+cam.x;
  posmcABS.y=p.posScreen.y+cam.y;
  posminimc.x=posmcABS.x*resize/100+m->posminimap.x;
  posminimc.y=posmcABS.y*resize/100+m->posminimap.y-10;
  return posminimc;
}

void displaymap(minimap m,SDL_Surface *screen)
{
  SDL_BlitSurface(m.minibg,NULL,screen,&m.posminimap);
  SDL_BlitSurface(m.minimc,NULL,screen,&m.posminimc);
}
void freeminimap(minimap *m)
{
  SDL_FreeSurface(m->minibg);
  SDL_FreeSurface(m->minimc);
}
void displaytime(int *time)
{
   Uint32 aaa;
   aaa=SDL_GetTicks();
   *time=(int)aaa/1000;

   
   
}

SDL_Color GetPixel(SDL_Surface *pSurface, int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}

int collisionMC(perso p, SDL_Surface *mask)
{
  
  SDL_Rect MChitbox[8];
  SDL_Color white={255,255,255};
  int col=0;
  MChitbox[0].x=p.posScreen.x;
  MChitbox[0].y=p.posScreen.y;
  MChitbox[1].x=p.posScreen.x+p.posSprite.w/2;
  MChitbox[1].y=p.posScreen.y;
  MChitbox[2].x=p.posScreen.x+p.posSprite.w;
  MChitbox[2].y=p.posScreen.y;
  MChitbox[3].x=p.posScreen.x+p.posSprite.w;
  MChitbox[3].y=p.posScreen.y+p.posSprite.h/2;
  MChitbox[4].x=p.posScreen.x+p.posSprite.w;
  MChitbox[4].y=p.posScreen.y+p.posSprite.h;
  MChitbox[5].x=p.posScreen.x+p.posSprite.w/2;
  MChitbox[5].y=p.posScreen.y+p.posSprite.h;
  MChitbox[6].x=p.posScreen.x;
  MChitbox[6].y=p.posScreen.y+p.posSprite.h;
  MChitbox[7].x=p.posScreen.x;
  MChitbox[7].y=p.posScreen.y+p.posSprite.h/2;
  for (int i=0;(i<8);i++)
  {
    if (((GetPixel(mask,MChitbox[i].x,MChitbox[i].y)).r==255)&&((GetPixel(mask,MChitbox[i].x,MChitbox[i].y)).g==255)&&((GetPixel(mask,MChitbox[i].x,MChitbox[i].y)).b==255))
    {
    col=1;
    break;
  }}
  return col;
}
