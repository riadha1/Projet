#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct 
{
	SDL_Surface * sprite;
	SDL_Rect posScreen;
	SDL_Rect posSprite;
	int num;
	int direction;
	int Signal;
	
	
}perso;

void init(perso* p,int numperso);
void deplacerPerso(perso *p);
void afficherPerso(perso p,SDL_Surface* screen);
void deplacerPerso(perso *p);
void animerPerso(perso *p);
void saut(perso *p);

#endif // HEADER_H_INCLUDED