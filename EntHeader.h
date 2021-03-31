#ifndef FONCTIONS_H_
#define FONCTIONS_H_

typedef struct{
  int type; //1 Swordsman 2 Archer 3 Shield boy
  int id;
  int hp;
  int speed;
  int x;
  int y;
  int LeftBound;
  int RightBound;
  int range;
  SDL_Surface * sprite;
  SDL_Rect rect;
}data;

struct Ennemi{
  data d;
  struct Ennemi * suiv;
};

void initEnnemi(Ennemi * e);
void initGlobalEnnemi(int n, Ennemi * e, int lvl);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e);
void deplacerIA( Ennemi * e);

#endif
