#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "test.h"
//background
void initialiser_Background(background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;

};

void aficherBack(background b, SDL_Surface* screen)
{
Mix_Music *music;

Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
music = Mix_LoadMUS("sound.wav");
Mix_PlayMusic(music,-1);

SDL_BlitSurface(b.backgroundImg,&b.backgroundPos,screen,NULL);

};
