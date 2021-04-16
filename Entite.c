#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "Entite.h"
#include "perso.h"

void initEnnemi(Ennemi e[]){
  for(int i = 0; i < 10; i++){
    e[i].hp = 1;
    e[i].type = 1;
    e[i].speed = 2;
    e[i].range = 20;
    e[i].sprite = IMG_Load("Sprite Sheets/Skelly Boy/Walk.png");
    e[i].spriteb = IMG_Load("Sprite Sheets/Skelly Boy/Walkb.png");
    e[i].posScreen.x = 100 + i * 100;
    e[i].posScreen.y = 150;
    e[i].RightBound = e[i].posScreen.x + 50;
    e[i].LeftBound = e[i].posScreen.x - 50;
    e[i].frame = 0;
    for(int j = 0; j < 4; j++){
      e[i].rect[j].x = j * 150;
      e[i].rect[j].y = 0;
      e[i].rect[j].h = 150;
      e[i].rect[j].w = 150;
    }
    e[i].Dir = 1;
  }
}

void afficherEnnemi(Ennemi e[], SDL_Surface * screen){
  for(int i = 0; i < 10; i++){
    if(e[i].Dir == 1){
      SDL_BlitSurface(e[i].sprite, &e[i].rect[e[i].frame], screen, &e[i].posScreen);
    }
    if(e[i].Dir == -1){
      SDL_BlitSurface(e[i].spriteb, &e[i].rect[e[i].frame], screen, &e[i].posScreen);
    }
  }
}

void deplacer(Ennemi e[]){
  int Detection = 0;
  for(int i = 0; i < 10; i++){
    switch(e[i].type){
      case 1:
        e[i].posScreen.x = e[i].posScreen.x + e[i].speed * e[i].Dir;
        if(e[i].posScreen.x >= e[i].RightBound){
          e[i].Dir = -1;
          e[i].frame = 0;
        }
        if(e[i].posScreen.x <= e[i].LeftBound){
          e[i].Dir = 1;
          e[i].frame = 0;
        }
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        break;
    }
  }
}

int collisionBB( perso p, Ennemi e[]){
  int col = 0;
  for(int i = 0; i < 10; i++){
    if((abs(e[i].posScreen.x - p.posScreen.x) <= ((e[i].posScreen.w + p.posSprite.w) / 2))&&(abs(e[i].posScreen.y - p.posScreen.y) <= ((e[i].posScreen.h + p.posSprite.h) / 2))){ //Edit this cuz player instantly
      col = 1;
    }
    else col = 0;
  }
  return col;
}

void animerEnnemi(Ennemi e[]){
  for(int i = 0; i < 10; i++){
    e[i].frame++;
    if(e[i].frame > 4){
      e[i].frame = 0;
    }
  }
}

void Liberer(Ennemi e[]){
  for(int i = 0; i < 10; i++){
    SDL_FreeSurface(e[i].sprite);
  }
}
