#ifndef LOT3_H_INCLUDED
#define LOT3_H_INCLUDED

typedef struct
{
  SDL_Surface *minimg;
  SDL_Rect posminimap;
  SDL_Surface *minimc;
  SDL_Rect posminimc;
}minimap;
SDL_Rect MAJminimap(SDL_Rect posmc,int resize);
void freeminimap(minimap *m);
void initmap(minimap *m);
void displaymap(minimap m,SDL_Surface *screen);
void displaytime(int *time);
int collisionMC(character c, SDL_Surface *mask);
int AI(grid g, int cpu);

#endif // LOT3_H_INCLUDED
