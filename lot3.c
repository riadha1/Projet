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
  m->minibg=IMG_Load("minibg.jpg");
  m->posminimap.x=0;
  m->posminimap.y=972;
  m->minimc=IMG_Load("minichar.png");
}
SDL_Rect MAJminimap(perso p,minimap *m,int resize)
{
  /*posminimc.x=p.posScreen.x+m->posminimap.x;
  posminimc.y=p.posScreen.y+m->posminimap.y;*/
SDL_Rect posmcABS,posminimc;
  posmcABS.x=p.posScreen.x;//+cam.x;
  posmcABS.y=p.posScreen.y;//+cam.y;
  posminimc.x=posmcABS.x*resize/100+m->posminimap.x;
  posminimc.y=posmcABS.y*resize/100+m->posminimap.y;
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

/*Uint32 GetPixel(SDL_Surface *surf, int x, int y)
{
int bpp = surf->format->BytesPerPixel;
Uint8 *p = (Uint8 *)surf->pixels + y * surf->pitch + x * bpp;

switch (bpp)
{
	case 1:
		return *p;

	case 2:
		return *(Uint16 *)p;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;

	case 4:
		return *(Uint32 *)p;

	default:
		return 0;
}
}*/

int collisionMC(perso p, SDL_Surface *mask)
{
  SDL_Rect MChitbox[8];
  SDL_Color color;
  int col=0;
  MChitbox[0].x=p.posScreen.x;
  MChitbox[0].y=p.posScreen.y;
  MChitbox[0].h=1;
  MChitbox[0].w=1;
  MChitbox[1].x=p.posScreen.x+p.posSprite.w/2;
  MChitbox[1].y=p.posScreen.y;
  MChitbox[1].h=1;
  MChitbox[1].w=1;
  MChitbox[2].x=p.posScreen.x+p.posSprite.w;
  MChitbox[2].y=p.posScreen.y;
  MChitbox[2].h=1;
  MChitbox[2].w=1;
  MChitbox[3].x=p.posScreen.x+p.posSprite.w;
  MChitbox[3].y=p.posScreen.y+p.posSprite.h/2;
  MChitbox[3].h=1;
  MChitbox[3].w=1;
  MChitbox[4].x=p.posScreen.x+p.posSprite.w;
  MChitbox[4].y=p.posScreen.y+p.posSprite.h;
  MChitbox[4].h=1;
  MChitbox[4].w=1;
  MChitbox[5].x=p.posScreen.x+p.posSprite.w/2;
  MChitbox[5].y=p.posScreen.y+p.posSprite.h;
  MChitbox[5].h=1;
  MChitbox[5].w=1;
  MChitbox[6].x=p.posScreen.x;
  MChitbox[6].y=p.posScreen.y+p.posSprite.h;
  MChitbox[6].h=1;
  MChitbox[6].w=1;
  MChitbox[7].x=p.posScreen.x;
  MChitbox[7].y=p.posScreen.y+p.posSprite.h/2;
  MChitbox[7].h=1;
  MChitbox[7].w=1;
  for (int i=0;i<8;i++)
  {
    color=GetPixel(mask,MChitbox[i].x,MChitbox[i].y);
    if ((color.r==0)||(color.g==0)||(color.b==0))
    {
      col=1;
      break;
    }
    else col=0;
    //printf("pixel color is %d,%d,%d and collision=%d and i =%d\n",color.r,color.g,color.b,col,i);
  }
  return col;
}
