#include "enigmehedi.h"


enigmeh generer(){
    enigmeh e;
    int solution,ajout;
    int i;

    int coeffQ[4];
    /* tableau de 4 entiers ,, les entiers sont les coefficients d'equation
    generés aleatoirement ulterierement
    */

/*---------remplissage du tableau avec des entiers aleatoires---------*/ 
    srand( time( NULL ) );
    coeffQ[0]=rand() % 20;
    coeffQ[1]=coeffQ[0]+4;
    coeffQ[2]=coeffQ[1]+15;
    coeffQ[3]=coeffQ[0]+coeffQ[2];



	sprintf(e.question,"(%d + %d)* %d - %d =?",coeffQ[0],coeffQ[1],coeffQ[2],coeffQ[3]);
    /*generer le question avec les entiers du tableau coeff[]
    exemple:
    (13 + 17)* -3 - 10 =?
    */
    
    
    solution=(coeffQ[0]+coeffQ[1])*coeffQ[2]-coeffQ[3];//calculer la solution
    
    
    
/*--------mettre 3 reponses (1 vrai et 2 fausses) dans rep1 , rep2 et rep3 ----------*/
    srand( time( NULL ) );
    e.solution =1 + rand() % 3;
    if (e.solution==1)
    {
        sprintf(e.rep1,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep2,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",solution+ajout);
    }
    if (e.solution==2)
    {
        sprintf(e.rep2,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",solution+ajout);
    }
    if (e.solution==3)
    {
        sprintf(e.rep3,"%d",solution);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep1,"%d",solution+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep2,"%d",solution+ajout);
    }
    return e;
    
    

}
void afficherEnigme(enigmeh *e, SDL_Surface * screen){
    
/*---------declaration des variables-----------*/    
SDL_Surface *texte,*R1,*R2,*R3,*back,*bouton;
SDL_Rect posQ,pos1,pos2,pos3,posbouton1,posbouton2,posbouton3;
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police = NULL,*police2 = NULL;


/*-------chargement des images----------*/
bouton=IMG_Load("enigmehedi/bouton.png");
back=IMG_Load("enigmehedi/background.png");


TTF_Init();//initialiser le TTF
    
/*----------charger les police----------*/    
police = TTF_OpenFont("enigmehedi/arial.ttf", 95);
police2 = TTF_OpenFont("enigmehedi/arial2.ttf", 95);




/*---------mettre les chaines caracteres dans des images (SDL_Surfaces)-----------*/
    texte = TTF_RenderText_Blended(police, e->question, couleurNoire);
    R1 = TTF_RenderText_Blended(police2, e->rep1, couleurNoire);
    R2 = TTF_RenderText_Blended(police2, e->rep2, couleurNoire);
    R3 = TTF_RenderText_Blended(police2, e->rep3, couleurNoire);



/*---------mettre les positions de : question + 3 reponses + 3 bouttons ---------*/
    posQ.x=50;
    posQ.y=50;
    pos1.x=100;
    pos1.y=300;
    posbouton1.x=30;
    posbouton1.y=300;
    pos2.x=450;
    pos2.y=300;
    posbouton2.x=380;
    posbouton2.y=300;
    pos3.x=750;
    pos3.y=300;
    posbouton3.x=680;
    posbouton3.y=300;


/*---------affichage de :background + 3 bouttons + 3 reponses ---------*/
    SDL_BlitSurface(back, NULL, screen, NULL); 
    SDL_BlitSurface(texte, NULL, screen, &posQ); /* Blit du texte */
    SDL_BlitSurface(bouton,NULL,screen,&posbouton1);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton2);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton3);
    SDL_BlitSurface(R1, NULL, screen, &pos1); /* Blit du texte */
    SDL_BlitSurface(R2, NULL, screen, &pos2); /* Blit du texte */
    SDL_BlitSurface(R3, NULL, screen, &pos3); /* Blit du texte */
}
int mainhedi()
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
SDL_Surface *back=NULL;
SDL_Surface *win=NULL;
SDL_Surface *loss=NULL;
win=IMG_Load("enigmehedi/enigme1_win.jpg");
loss=IMG_Load("enigmehedi/enigme1_loss.jpg");
screen=SDL_SetVideoMode (1095,630,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Event event;
//SDL_Surface *background=NULL;
SDL_WM_SetCaption("ENIGMEALEA\t1",NULL);
int  running=1;
int reponse=-1;
enigmeh e;
e=generer();/*generer aleatoirement une enigme
enigme contient {une question , 3 reponses , le nombre de solution correcte}
et l'enregistrer dans e.
*/
while (running)
{
    afficherEnigme(&e,screen);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
    {

        switch(event.type)
        {
        case SDL_QUIT:

            running=0;
        break;
        case SDL_KEYDOWN:
        /*
        repondre avec le clavier
        a : reponse 1
        z : reponse 2
        e : reponse 3
        */
            switch (event.key.keysym.sym)
            {
            
            case SDLK_a :
                if (e.solution==1)
                {
                     reponse=1;
                    printf("vrai");
                    ////////////////
                }
                else {
                    reponse=0;
                    printf("faux");
                }
                
            break;
            case SDLK_z :
                if (e.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            break;
            case SDLK_e:
                if (e.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                   reponse=0;
                    printf("faux");
                }
            break;
            }
        break;
        case SDL_MOUSEBUTTONDOWN://repondre avec le souris
            if (event.motion.x >= 30 && event.motion.x <= 303 && event.motion.y >= 300 && event.motion.y <= 438)//cad:si on clique sur boutton1
            {
                if (e.solution==1)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 420 && event.motion.x <= 693 && event.motion.y >= 300 && event.motion.y <= 438)//clique sur boutton2
            {
                if (e.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 720 && event.motion.x <= 993 && event.motion.y >= 300 && event.motion.y <= 438)//clique sur boutton3
            {
                if (e.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            break;
        }
    }


if (reponse!=-1)
{
if (reponse==1)
{
    /* si la reponse est vraie , on affiche "good job" 
    flip screen four refraichir le screen ,
    delai de 5 sec puis quit, */
    SDL_BlitSurface(win, NULL, screen, NULL); /* Blit du texte */
    SDL_Flip(screen);

    SDL_Delay(5000);
    running=0;
}
else  
{ /*
    si faux ,, on affiche "faux",, delai de 5 sec ,, puis quit
*/
    SDL_BlitSurface(loss, NULL, screen, NULL); /* Blit du texte */
    SDL_Flip(screen);

    SDL_Delay(5000);
    running=0;
}
}
}
 SDL_FreeSurface(back);
 SDL_FreeSurface(win);
 SDL_FreeSurface(loss);

    SDL_QUIT;
 return reponse; 
}