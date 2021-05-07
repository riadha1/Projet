#ifndef LOT3_H_INCLUDED
#define LOT3_H_INCLUDED
#include "perso.h"
typedef struct
{
  SDL_Surface *minibg;
  SDL_Rect posminimap;
  SDL_Surface *minimc;
  SDL_Rect posminimc;
}minimap;
SDL_Rect MAJminimap(perso p,minimap *m,int resize,SDL_Rect cam);//missing camera
void freeminimap(minimap *m);
void initmap(minimap *m);
void displaymap(minimap m,SDL_Surface *screen);
void displaytime(int *time);
SDL_Color GetPixel(SDL_Surface *pSurface, int x,int y);
int collisionMC(perso p, SDL_Surface *mask);
//int AI(grid g, int cpu);

#endif // LOT3_H_INCLUDED
