#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "EntHeader.h"
#include "perso.h"



/*void initEnnemi(Ennemi * e){
  switch(e->d.type){
    case 1: //Skelly
      e->d.hp = 1;
      e->d.speed = 2;
      e->d.range = 20;

      //Init frames
      for(int i = 0; i < 4; i++){
        if(i == 0){
          EntSprites * nouv; //A verifier
          nouv = (EntSprites *) malloc(sizeof(EntSprites));
          *nouv = e->d.s; //A verifier
          (*nouv)->frame.x = i * 150;
          (*nouv)->frame.y = 0;
          (*nouv)->frame.w = 150;
          (*nouv)->frame.h = 150;
          e->d.s = *nouv;
        }
        else if(i == 3){
          EntSprites tmp, holder;
          tmp = e->d.s;
          while(tmp->suiv != NULL){
            tmp = tmp->suiv;
          }
          holder->frame.x = i * 150;
          holder->frame.y = 0;
          holder->frame.w = 150;
          holder->frame.h = 150;
          tmp->suiv = holder;
          holder->suiv = e->d.s;
        }
        else{
          EntSprites tmp, holder;
          tmp = e->d.s;
          while(tmp->suiv != NULL){
            tmp = tmp->suiv;
          }
          holder->frame.x = i * 150;
          holder->frame.y = 0;
          holder->frame.w = 150;
          holder->frame.h = 150;
          tmp->suiv = holder;
        }
      }
      e->d.sprite = IMG_Load("Sprite Sheets/Skelly Boy/Walk.png");
      break;
    case 2: //Ranged
      e->d.hp = 1;
      e->d.speed = 3;
      e->d.range = 40;
      //e->d.sprite = IMGLoad("");
      //e->d.rect.w = ??
      //e->d.rect.h = ??
      break;
    case 3: //Shield boy
      e->d.hp = 2;
      e->d.speed = 1;
      e->d.range = 15;
      //e->d.sprite = IMGLoad("");
      //e->d.rect.w = ??
      //e->d.rect.h = ??
      break;
    default:
      break;
  }
}*/

void initGlobalEnnemi(int n, Ennemi e, int lvl){
  Ennemi tmp, * nouv;
  tmp = e;
  for(int i = 0; i < n; i++){
    nouv = (Ennemi*) malloc(sizeof(Ennemi));
    //Initialisation selon niveau
    switch(lvl){
      case 1:
        switch(i){
          case 0:
            (*nouv)->d.type = 1;
            (*nouv)->d.rect.x = 500;
            (*nouv)->d.rect.y = 500;
            (*nouv)->d.RightBound = (*nouv)->d.rect.x + 50;
            (*nouv)->d.LeftBound = (*nouv)->d.rect.x - 50;
            initEnnemi(*nouv);
            e = *nouv;
            break;
          case 1:
          /*nouv->d.type = ??
          nouv->d.x = ??
          nouv->d.y = ??
          nouv->d.RightBound = x + ??
          nouv->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 2:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 3:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 4:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 5:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 6:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 7:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 8:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 9:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 10:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 11:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 12:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 13:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          case 14:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(*nouv);
            break;
          default:
            break;
        }
        break;
      case 2:
        break;
      case 3:
        break;
    }
    if(i == 0){
      e = *nouv;
    }
    else{
      tmp = e;
      while(tmp->suiv != NULL){
        tmp = tmp->suiv;
      }
      tmp->suiv = *nouv;
    }
  }
}

void afficherEnnemi(Ennemi e, SDL_Surface * screen){
  SDL_BlitSurface(e.d.sprite, &e.d.s->frame, screen, &e.d.rect);
}

void animerEnnemi( Ennemi e){

}

void deplacer(Ennemi e){
  int Detection = 0;
  Ennemi tmp;
  tmp = e;
  while(tmp.suiv != NULL){
    tmp.d.Dir = 1;
    switch(tmp.d.type){
      case 1:
        tmp.d.rect.x = tmp.d.rect.x + tmp.d.speed * tmp.d.Dir;
        if(tmp.d.rect.x >= tmp.d.RightBound){
          tmp.d.Dir = -1;
        }
        if(tmp.d.rect.x <= tmp.d.LeftBound){
          tmp.d.Dir = 1;
        }
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        break;
    }
    tmp = tmp.suiv;
  }
}

int collisionBB( perso p, Ennemi e){
  int col = 0;
  Ennemi tmp;
  tmp = e;
  while(tmp->suiv != NULL){
    if((abs(e->d.rect.x - p.posScreen.x) <= ((e->d.rect.w + p.posSprite.w) / 2))&&(abs(e->d.rect.y - p.posScreen.y) <= ((e->d.rect.h + p.posSprite.h) / 2))){ //Edit this cuz player instantly
      col = 1;
    }
    else col = 0;
    tmp = tmp->suiv;
  }
  return col;
}

void deplacerIA( Ennemi e){ //Allah ysahhel

}
