#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include"enigme.h"


int  enigme(SDL_Surface *screen,int* e1,int* e2,int* e3,int* e4,int* e5,int *close,int rep)
{

TTF_Init();


    int r=0, 
    A=0; 

  do {
    srand(time(NULL));
   r=rand()%12+1; 
   printf("%d\n",r );
 } while(r==(*e1)||r==(*e2)||r==(*e3)||r==(*e4)||r==(*e5));


  if (rep==1) (*e1)=r;
   if (rep==2) (*e2)=r;
    if (rep==3) (*e3)=r;
    if (rep==4) (*e4)=r;
      if (rep==5) (*e5)=r;


      FILE* fichier=NULL; 
      FILE* fichierr=NULL;
      
      fichier=fopen("fichier/question.txt", "r");
      fichierr=fopen("fichier/reponse.txt", "r");

    char chaine[256]=""; 
    char chainer[256]="";

int i =0;

while (fgets (chaine, 256, fichier ) != NULL && fgets (chainer, 256, fichierr ) !=NULL) 
{
  i++;
  if (i==r) { 
break;
  }
}

    SDL_Surface  *texte = NULL, 
    *fond = NULL, 
     *rp =NULL;  
    SDL_Rect position;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurNoire = {0,0,0};


    fond = IMG_Load("graphic/back.jpg");
    police = TTF_OpenFont("graphic/font.ttf", 25);
    police1 = TTF_OpenFont("graphic/font.ttf", 30);
    texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
    rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);

    SDL_Event event; 
    int continuer = 1; 

    while (continuer)
    {


          SDL_BlitSurface(fond, NULL, screen, NULL);

        position.x = 170;
        position.y = 200;
        SDL_BlitSurface(texte, NULL, screen, &position);

        position.x = 170;
        position.y = 370;
        SDL_BlitSurface(rp, NULL, screen, &position);

        SDL_Flip(screen);



      SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT: 
                continuer = 0;
                (*close)=1;
                break;
                case SDL_KEYDOWN: 
            			switch (event.key.keysym.sym)
        {

          case SDLK_KP1: 

        if (r==1||r==4||r==7||r==10) 
        A=1 ; 
         continuer=0; 
break;

case SDLK_KP2:
     if (r==2||r==5||r==8||r==11) 
     A=1;
     continuer=0;
break;

case SDLK_KP3:
     if (r==3||r==6||r==9||r==12) 
     A=1;
     continuer=0;
break;
}
       }

   }


    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);

return A; 
}
int mainenigme()
{
        int nb_enigme=5;
        int hauteur_fenetre = 700,
        largeur_fenetre = 1100;



    SDL_Init(SDL_INIT_VIDEO);

    
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL); 

  int enigme_right=0 
  ,e1=0,e2=0,e3=0,e4=0,e5=0 , 
  rep=0;  

int close=0; 

for (int i=0;i<nb_enigme;i++)
{
  rep++; 
enigme_right+=enigme(screen,&e1,&e2,&e3,&e4,&e5,&close,rep);
if (close) break;
}


if (enigme_right>=(nb_enigme/2)+1) printf("win\n");
else printf("lose\n");


    SDL_Quit();

    return 0;
}
