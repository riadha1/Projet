#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "LevelsHeader.h"
#include "EntHeader.h"


void initLevel(int n){
  switch(n){
    case 1:
    Level1(n);
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
  }
}

void Level1(int n){
  int Nbe = 15;
  Ennemi * e;
  initGlobalEnnemi(Nbe, e, n);
}
