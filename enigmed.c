/**
* @file enigme.c
* @brief enigme statique.
* @author med ali lassoued
* @version 
* @date 05, 05, 2021
*
* enigme statique *
*/
#include "enigmed.h"

/**
* @brief Tintialliser  .
* @param e enigme
* @param
* @return Nothing
*/
void init_enigme(enigmed * e, int x, int y, SDL_Surface * img) 
{

	e->p.x=x;   /*!< intiallisation*/
	e->p.y=y;	
	e->img=img;


}

/**
* @brief pour afficher enigme   .
* @param e enigme
* @param e screen
* @  screen  notre fenetre 
* @return Nothing
*/
void afficherEnigmed(enigmed e, SDL_Surface * screen)
{
			
	SDL_BlitSurface(e.img,NULL,screen, &e.p); 
}


int maindali()
{
	SDL_Surface  *screen;
	SDL_Event event;
	enigmed e,p1,p2,fail,pass; /*!< déclaration */
	int game=1;

	SDL_Init(SDL_INIT_VIDEO);
        screen= SDL_SetVideoMode(1150,647,32,SDL_HWSURFACE |  SDL_DOUBLEBUF );/*!< intialiser l'ecran*/

	init_enigme(&e, 0, 0, IMG_Load("enigmed/enigme3.png"));
	init_enigme(&p1, 25, 110, IMG_Load("enigmed/perso1.png"));
	init_enigme(&p2, 39, 40, IMG_Load("enigmed/perso2.png"));
	init_enigme(&fail, 50, 0, IMG_Load("enigmed/fail.png"));
	init_enigme(&pass, 0, 0, IMG_Load("enigmed/pass.png"));

        if (screen == NULL)
        {
                fprintf(stderr,"Impossible de charger le mode vidéo : %s\n",SDL_GetError());
                exit(EXIT_FAILURE);
        }


	while(game) /*!<boucle  de jeu */
	{
		afficherEnigmed(e,screen);/*!<affichage enigme */	
				afficherEnigmed(p1,screen);/*!<affichage perso1 */
                afficherEnigmed(p2,screen);/*!<affichage perso 2 */
		
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT:
				game = 0;/*!<sortir de jeu  */
			break;

			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
					case SDL_BUTTON_LEFT:/*!<detecter  le clique de souris */
if ((event.button.x >= p1.p.x) && (event.button.x <= p1.p.x+30) && (event.button.y >= p1.p.y) &&(event.button.y <=p1.p.y+60 )) 
						{
						/*!<cas gangant */
						afficherEnigmed(pass,screen);	
						game=0; 
						
						
						}
if ((event.button.x >= p2.p.x) && (event.button.x <= p2.p.x+35) && (event.button.y >= p2.p.y) &&(event.button.y <=p2.p.y+60 ))
						{
						/*!cas perdan*/
 						afficherEnigmed(fail,screen);
						
					
						}

					break;
					default:
					break;
				}
				break;
				default:
				break;
		}
	


	SDL_Flip(screen) ; 
	}
	SDL_Delay(1000);
	SDL_FreeSurface(e.img);
	SDL_FreeSurface(p1.img);
	SDL_FreeSurface(p2.img);	
	SDL_Quit();

	return 1;
}
