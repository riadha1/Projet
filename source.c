#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

void setrects(SDL_Rect* clip, int n)
{
  for (int i=0;i<8;i++)
  {
    clip[0].x=i*1920
    clip[0].y=0
    clip[0].h=1080
    clip[0].w=i*1920+1920
  }

}
