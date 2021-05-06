#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "menu.h"
#include "LevelsHeader.h"


int main(int argc, char** argv)
{
  	int r,np;

  	r = menu();
    np =menu2();
  
 	initLevel(r,np);
  
  return 0;
}
