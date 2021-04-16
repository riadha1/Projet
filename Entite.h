#ifndef ENTITE_H_
#define ENTITE_H_

#include "perso.h"

typedef struct{
  int type; //1 Swordsman 2 Archer 3 Shield boy
  int id;
  int hp;
  int speed;
  int LeftBound;
  int RightBound;
  int range;
  int Dir;
  int frame;
  SDL_Surface * sprite;
  SDL_Surface * spriteb;
  SDL_Rect rect[4];
  SDL_Rect posScreen;
}Ennemi;


void initEnnemi(Ennemi e[]);
void afficherEnnemi(Ennemi e[], SDL_Surface * screen);
void deplacer(Ennemi e[]);
int collisionBB(perso p, Ennemi e[]);
void animerEnnemi(Ennemi e[]);
void Liberer(Ennemi e[]);

#endif
