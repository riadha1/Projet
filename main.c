#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "menu.h"
#include "LevelsHeader.h"
#include "EntHeader.h"

int main(int argc, char** argv)
{
  int r;
  r = menu();
  //r = 1;
  initLevel(r);
  return 0;
}
