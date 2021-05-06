#include "background.h"

void initBack(background * b){
    b->image=IMG_Load("background resources/stage1.png");
    
    b->camera.x=0;
    b->camera.y=200;
    b->camera.h=400;
    b->camera.w=400;

    b->camera2.x=0;
    b->camera2.y=200;
    b->camera2.h=400;
    b->camera2.w=400;

    
    b->music=Mix_LoadMUS("background resources/music.mp3");
    Mix_PlayMusic(b->music, -1);

}


void aficherBack(background b, SDL_Surface * screen){
    SDL_Rect pos={400,0,400,400};
    SDL_Surface *trait;//ajout d"un trait separant les deux cameras
    trait=IMG_Load("background resources/trait.png");//loadind trait.png
    SDL_BlitSurface(b.image , &b.camera, screen  , NULL);
    SDL_BlitSurface(b.image,&b.camera2,screen, &pos);
    SDL_BlitSurface(trait,NULL,screen, &pos);//affichage d trait


}

void scrolling (background * b, int direction, int pasAvancement){
  
       switch (direction)
    {
    case 'R':
        if (b->camera.x <= 7200) b->camera.x += pasAvancement ;
        break;
    
    case 'L':
        if (b->camera.x >= 0) b->camera.x -= pasAvancement;
        break;
    case 'U':
        if (b->camera.y >= 0) b->camera.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camera.y <= 200) b->camera.y += pasAvancement;
        break;        
    } 
}

void scrolling2 (background * b, int direction, int pasAvancement){
   
       switch (direction)
    {
    case 'R':
        if (b->camera2.x <= 7200) b->camera2.x += pasAvancement ;
        break;
    
    case 'L':
        if (b->camera2.x >= 0) b->camera2.x -= pasAvancement;
        break;
    case 'U':
        if (b->camera2.y >= 0) b->camera2.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camera2.y <= 200) b->camera2.y += pasAvancement;
        break;        
    } 

    
    
}