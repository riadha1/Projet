#include "background.h"

void initBack(background * b,int x,int y){
    b->image=IMG_Load("background resources/stage1.png");
    
    b->camerasolo.x=0;
    b->camerasolo.y=0;
    b->camerasolo.w=x;
    b->camerasolo.h=y;

    b->camera.x=0;
    b->camera.y=0;
    b->camera.h=y;
    b->camera.w=x/2;

    b->camera2.x=x/2;
    b->camera2.y=0;
    b->camera2.h=y;
    b->camera2.w=x/2;

    
    b->music=Mix_LoadMUS("background resources/music.mp3");
    Mix_PlayMusic(b->music, -1);

}


void aficherBack(background b, SDL_Surface * screen,int x,int y,int np){
    if (np == 1)
    {
        SDL_BlitSurface(b.image,&(b.camerasolo),screen,NULL);
    }
    if (np == 2){
    SDL_Rect pos={x/2,0,x/2,y};
    SDL_Surface *trait;//ajout d"un trait separant les deux cameras
    trait=IMG_Load("background resources/trait.png");//loadind trait.png
    SDL_BlitSurface(b.image , &b.camera, screen  , NULL);
    SDL_BlitSurface(b.image,&b.camera2,screen, &pos);
    SDL_BlitSurface(trait,NULL,screen, &pos);//affichage d trait
}

}

void scrollingsolo (background * b, int direction, int pasAvancement){
  
       switch (direction)
    {
    case 'R':
        if (b->camerasolo.x <= 3000-(1366)) b->camerasolo.x += pasAvancement ;
        break;
    
    case 'L':
        if (b->camerasolo.x >= 1366/2) b->camerasolo.x -= pasAvancement;
        break;
    /*case 'U':
        if (b->camerasolo.y >= 0) b->camerasolo.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camerasolo.y <= 200) b->camerasolo.y += pasAvancement;
        break;*/        
    } 
}
void scrolling (background * b, int direction, int pasAvancement){
  
       switch (direction)
    {
    case 'R':
        if (b->camera.x <= 3000-(1366/2)) b->camera.x += pasAvancement ;
        break;
    
    case 'L':
        if (b->camera.x >= 1366/2) b->camera.x -= pasAvancement;
        break;
    /*case 'U':
        if (b->camera.y >= 0) b->camera.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camera.y <= 200) b->camera.y += pasAvancement;
        break; */       
    } 
}

void scrolling2 (background * b, int direction, int pasAvancement){
   
       switch (direction)
    {
    case 'R':
        if (b->camera2.x <= 3000-(1366/2)) b->camera2.x += pasAvancement ;
        break;
    
    case 'L':
        if (b->camera2.x >= 1366/2) b->camera2.x -= pasAvancement;
        break;
    /*case 'U':
        if (b->camera2.y >= 0) b->camera2.y  -= pasAvancement;
        break;
    case 'D':
        if (b->camera2.y <= 200) b->camera2.y += pasAvancement;
        break;  */      
    } 

    
    
}