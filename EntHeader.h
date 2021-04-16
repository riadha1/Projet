#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include "perso.h"

struct SpriteStruct{
  SDL_Rect frame;
  struct SpriteStruct * suiv;
};

typedef struct SpriteStruct * EntSprites;

typedef struct{
  int type; //1 Swordsman 2 Archer 3 Shield boy
  int id;
  int hp;
  int speed;
  int LeftBound;
  int RightBound;
  int range;
  int Dir;
  SDL_Surface * sprite;
  SDL_Rect rect;
  EntSprites s;
}data;

struct EntStruct{
  data d;
  struct EntStruct * suiv;
};

typedef struct EntStruct Ennemi;

void initEnnemi(Ennemi * e);
void initGlobalEnnemi(int n, Ennemi e, int lvl);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi e);
void deplacer( Ennemi e);
int collisionBB( perso p, Ennemi e);
void deplacerIA( Ennemi  e);

#endif
