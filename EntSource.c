#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "EntHeader.h"
#include "perso.h"

void initEnnemi(Ennemi * e){
  switch(e->d.type){
    case 1: //Regular
      e->d.hp = 1;
      e->d.speed = 2;
      e->d.range = 20;
      //e->d.sprite = IMGLoad("");
      //e->d.rect.w = ??
      //e->d.rect.h = ??
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
}

void initGlobalEnnemi(int n, Ennemi * e, int lvl){
  Ennemi * tmp, * nouv;
  tmp = e;
  for(int i = 0; i < n; i++){
    nouv = (Ennemi*) malloc(sizeof(Ennemi));
    //Initialisation selon niveau
    switch(lvl){
      case 1:
        switch(i){
          case 0:
            /*nouv->d.type = ??
            nouv->d.x = ??
            nouv->d.y = ??
            nouv->d.RightBound = x + ??
            nouv->d.LeftBound = x - ??*/
            initEnnemi(nouv);
            e = nouv;
            break;
          case 1:
          /*nouv->d.type = ??
          nouv->d.x = ??
          nouv->d.y = ??
          nouv->d.RightBound = x + ??
          nouv->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 2:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 3:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 4:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 5:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 6:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 7:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 8:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 9:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 10:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 11:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 12:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 13:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
            break;
          case 14:
          /*e->d.type = ??
          e->d.x = ??
          e->d.y = ??
          e->d.RightBound = x + ??
          e->d.LeftBound = x - ??*/
          initEnnemi(nouv);
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
      e = nouv;
    }
    else{
      tmp = e;
      while(tmp->suiv != NULL){
        tmp = tmp->suiv;
      }
      tmp->suiv = nouv;
    }
  }
}

void afficherEnnemi(Ennemi e, SDL_Surface * screen){

}

void animerEnnemi( Ennemi * e){

}

void deplacer( Ennemi * e){
  int Detection = 0;
  int Dir = 1;
  switch(e->d.type){
    case 1:
      e->d.x = e->d.x + speed * Dir;
      if(e->d.x >= e->d.RightBound){
        Dir = -1;
      }
      if(e->d.x <= e->d.LeftBound){
        Dir = 1;
      }
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
  }
  /*switch(Detection){
    case 0:
      e->d.x = e->d.x + speed * Dir;
      if(e->d.x >= e->d.RightBound){
        Dir = -1;
      }
      if(e->d.x <= e->d.LeftBound){
        Dir = 1;
      }
      break;
    case 1:
      Dir = -(posPlayer - e->d.x) / (posPlayer - e->d.x);
      break;
  }*/
}

int collisionBB( perso p, Ennemi e){
  int col = 0;
  Ennemi tmp;
  tmp = e;
  while(tmp.suiv != NULL){
    ss
    if(Abs(e.d.x - p.posSprite.x) <= ((e.d.rect.w + p.rect.w) / 2))&&(Abs(e.d.y - p.posSprite.y) <= ((e.d.rect.h + p.rect.h) / 2)){ //Edit this cuz player instantly
      col = 1;
    }
    else col = 0;
    tmp = tmp->suiv;
  }
  return col;
}

void deplacerIA( Ennemi * e){ //Allah ysahhel

}
