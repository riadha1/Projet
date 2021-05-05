#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED
typedef struct {
	SDL_Surface *backgroundImg;
  SDL_Rect backgroundPos;

}background;

void initialiser_Background(background *Backg);
void aficherBack(background b, SDL_Surface * screen);

#endif // JEUX_H_INCLUDED
