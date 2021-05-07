#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


/**
* @struct 
* @brief struct enigme
*/

typedef struct 
{
 SDL_Surface * img; /*!< Surface. */             
 SDL_Rect 	p;   /*!< Rectangle*/

}enigmed;
void init_enigme(enigmed * e, int x, int y, SDL_Surface * img);
void afficherEnigmed(enigmed e ,SDL_Surface * screen);
int maindali();