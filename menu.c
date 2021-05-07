#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "menu.h"

void setrects(SDL_Rect clips[13][8])
{
  for(int j=0;j<12;j++)
  {
    for (int i=0;i<8;i++)
    {
      clips[j][i].x=i*1920;
      clips[j][i].y=j*1080;
      clips[j][i].h=1080;
      clips[j][i].w=1920;
    }
  }
  for (int i=0;i<4;i++)
  {
    clips[12][i].x=i*1920;
    clips[12][i].y=12*1080;
    clips[12][i].h=1080;
    clips[12][i].w=1920;
  }
}

int menu()
{
  float s;
  s = 1;
  TTF_Init();
  int quit = 0;
  int frame=0;
  int framej=0;
  int r;
  Uint32 start;
  const int fps=60;
  TTF_Font *font=NULL;
  char a[3][10];
  strcpy (a[0],"Play");
  strcpy (a[1],"Settings");
  strcpy (a[2],"Exit");
  char b[3][20];
  strcpy (b[0],"Volume");
  strcpy (b[1],"Fullscreen Off");
  strcpy (b[2],"Back To Menu");
  SDL_Surface *text1[3],*text2[3],*image,*screen,*bar,*barbg,*skelly;
  SDL_Rect offset,postext,posvlm,poslid;
  SDL_Event event;
  SDL_Color white={255,255,255},red = {187, 0, 0},grey={128,128,128};
  font=TTF_OpenFont("resources menu/souls_font.ttf",90);
  int mx,my;
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,4096);
Mix_Music *music;
Mix_Chunk *btnsnd;
btnsnd=Mix_LoadWAV("resources menu/btnsnd.wav");
music=Mix_LoadMUS("resources menu/mainmenu.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(128/2);
  if( TTF_Init() == -1 )
  {
      printf( "Can't TTF:  %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
  }
  if(font==NULL)
  {
      printf( "Can't font bruh:  %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
  }
offset.x = 0;
offset.y = 0;
posvlm.x=960 - (386);
posvlm.y=405;
poslid.x=0;
poslid.y=0;
poslid.h=144;
poslid.w=386;
  if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
  {
      printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
  }
  image=IMG_Load("resources menu/1.png");
  bar=IMG_Load("resources menu/Bar.png");
  barbg=IMG_Load("resources menu/BarBG.png");
  skelly=IMG_Load("resources menu/Skelly.png");
  screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);

  if( screen == NULL )
  {
      printf( "Can't set video mode: %s\n", SDL_GetError( ) );
      return EXIT_FAILURE;
  }
  SDL_Rect rects[13][8];
  setrects(rects);
  if (image==NULL)
  {
  printf(" %s\n", SDL_GetError( ));
  return EXIT_FAILURE;
  }
int mouse=3;
int m = 0;
int kbon = 0;
int sett = 0;
int vol=0;
int FS = 0;
//start of menu cycle
while(quit == 0)
{
  //background render+get ticks
  SDL_BlitSurface(image,&rects[framej][frame],screen,&offset);
  start=SDL_GetTicks();
  frame++;
  if(frame==8)
  {
    frame=0;
    framej++;
  }
  if (framej==12)
  {
    if (frame==4)
    {
      framej=0;
      frame=0;
    }
  }
  //text & volume render
  for(int i=0;i<3;i++)
  {
    if(sett == 0)
    {
    if(kbon == 0 && mouse!=i)
    {
    text1[i]=TTF_RenderText_Blended(font,a[i],white);
    }
    else if (kbon ==0 && mouse==i)
    {
      text1[i]=TTF_RenderText_Blended(font,a[i],red);
    }
    else{
      if(i == m)
      {
        text1[i]=TTF_RenderText_Blended(font,a[i],red);
      }

      else
      {
        text1[i]=TTF_RenderText_Blended(font,a[i],white);
      }
    }
    postext.x=310;
    postext.y=440+i*100;
    SDL_BlitSurface(text1[i], NULL,screen,&postext);
    }
    if(sett == 1)
    {
    if(kbon == 0&& mouse!=i)
    {
    text2[i]=TTF_RenderText_Blended(font,b[i],white);
    }
    else if (kbon ==0 && mouse==i)
    {
      text2[i]=TTF_RenderText_Blended(font,b[i],red);
    }
    else
    {
      if(i == m)
      {
        text2[i]=TTF_RenderText_Blended(font,b[i],red);
      }
      else if (i!=m)
      {
        text2[i]=TTF_RenderText_Blended(font,b[i],white);
      }
    }
    postext.x=310;
    postext.y=440+i*100;
    SDL_BlitSurface(text2[i], NULL,screen,&postext);
    }
  }
  if(sett==1)
  {
    SDL_BlitSurface(barbg, NULL, screen,&posvlm);
    SDL_BlitSurface(bar, &poslid,screen,&posvlm);
    SDL_BlitSurface(skelly,NULL,screen,&posvlm);
  }
  //event handeling
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_MOUSEMOTION:
      {
      mx=event.motion.x;
      my=event.motion.y;
      if (sett==0)
      {
      if ((mx>=postext.x)&&(mx<=postext.x+125)&&(my>=440)&&(my<=440+70))
      {
      mouse=0;
      m=0;
      }
      else if((mx>=postext.x)&&(mx<=postext.x+250)&&(my>=440+100)&&(my<=440+100+70))
      {
      m=1;
      mouse=1;
      }
      else if ((mx>=postext.x)&&(mx<=postext.x+125)&&(my>=440+200)&&(my<=440+200+70))
      {
      mouse=2;
      m=2;
      }
      else
      {
        kbon=0;
        mouse=3;
        m=3;
      }
      }
      else if (sett==1)
      {
        if (((mx>=postext.x)&&(mx<=postext.x+250)&&(my>=440)&&(my<=440+70))||((mx>=postext.x+250)&&(mx<=posvlm.x+772)&&(my<=posvlm.y+144-53)&&(my>=posvlm.y+53)))
        {
        mouse=0;
        m=0;
        }
        else if((mx>=postext.x)&&(mx<=postext.x+450)&&(my>=440+100)&&(my<=440+100+70))
        {
        m=1;
        mouse=1;
        }
        else if ((mx>=postext.x)&&(mx<=postext.x+500)&&(my>=440+200)&&(my<=440+200+70))
        {
        mouse=2;
        m=2;
        }
        else
        {
          kbon=0;
          mouse=3;
          m=3;
        }
      }
        break;
      }
      case SDL_MOUSEBUTTONDOWN:
      {
        if( event.button.button == SDL_BUTTON_LEFT )
      {
        switch(sett)
        {
          case 0:
            if(m == 0){
              Mix_PlayChannel(-1, btnsnd, 0);
              r = 1;
              quit = 1;
            }
            if(m == 1)
            {
              Mix_PlayChannel(-1, btnsnd, 0);
              sett = 1;
              for (int i=0;i<3;i++)
              {
                SDL_FreeSurface(text1[i]);
              }
            }
            if(m == 2)
            {
              Mix_PlayChannel(-1, btnsnd, 0);
              r=0;
              quit = 1;
            }
          break;
          case 1:
            if(m == 2)
            {
              Mix_PlayChannel(-1, btnsnd, 0);
              sett = 0;
              for (int i=0;i<3;i++)
              {
                SDL_FreeSurface(text2[i]);
              }
            }
            if(m == 1)
            {
              Mix_PlayChannel(-1, btnsnd, 0);
              switch(FS)
              {
                case 0:
                  FS = 1;
                  strcpy(b[1], "Fullscreen On");
                  screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                break;
                case 1:
                  FS = 0;
                  strcpy(b[1], "Fullscreen Off");
                  screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);
                break;
                default:
                break;
              }
            }
            if(((mx>=posvlm.x+107)&&(mx<=posvlm.x+772-107)&&(my<=posvlm.y+144-53)&&(my>=posvlm.y+53)))
            {
              Mix_PlayChannel(-1, btnsnd, 0);
              poslid.w=mx-posvlm.x;
              s  = ((float)(mx-posvlm.x-107)/(665-107));
              Mix_VolumeMusic(s*128);
            }
          break;
          default:
          break;
        }
        break;
      }
      else break;
    }
      case SDL_QUIT:
      {
        r=0;
        quit = 1;
      }
      break;
      case SDL_KEYDOWN:
        if(event.key.keysym.sym == SDLK_ESCAPE)
        {
          if (sett==1)
          {
            Mix_PlayChannel(-1, btnsnd, 0);
            sett = 0;
            for (int i=0;i<3;i++)
            {
              SDL_FreeSurface(text2[i]);
            }
          }
        }
        if(event.key.keysym.sym == SDLK_UP)
        {
          if(kbon == 0)
          {
            m = 0;
            kbon = 1;
          }
          else {
            m--;
            if(m<0){
            m=2;
            }
          }
        }
        if(event.key.keysym.sym == SDLK_DOWN)
        {
          if(kbon == 0)
          {
            m = 0;
            kbon = 1;
          }
          else
          {
            m++;
            if(m>2)
            {
            m=0;
            }
          }
        }
        if(event.key.keysym.sym == SDLK_RIGHT)
        {
          if(m == 0)
          {
            s = s + ((float)(10)/100);
            if(s >= 1)
            {
              s = 1;
            }
            poslid.w = poslid.w + (((float)(10)/100) * 557);
            if(poslid.w >= 666)
            {
              poslid.w = 666;
            }
            Mix_VolumeMusic(s*128);
          }
        }
        if(event.key.keysym.sym == SDLK_LEFT)
        {
          if(m == 0)
          {
            s = s - ((float)(10)/100);
            if(s <= 0)
            {
              s = 0;
            }
            poslid.w = (int) poslid.w - (((float)(10)/100) * 557);
            if(poslid.w >= 667)
            {
              poslid.w = 0;
            }
            Mix_VolumeMusic(s*128);
          }
        }
        if(event.key.keysym.sym == SDLK_RETURN)
        {
          switch(sett)
          {
            case 0:
              if(m == 1)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                sett = 1;
                for (int i=0;i<3;i++)
                {
                  SDL_FreeSurface(text1[i]);
                }
              }
              if(m == 2)
              {
                r=0;
                quit = 1;
              }
            break;
            case 1:
              if(m == 2)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                sett = 0;
                for (int i=0;i<3;i++)
                {
                  SDL_FreeSurface(text2[i]);
                }
              }
              if(m == 1)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                switch(FS)
                {
                  case 0:
                    FS = 1;
                    strcpy(b[1], "Fullscreen On");
                    screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                  break;
                  case 1:
                    FS = 0;
                    strcpy(b[1], "Fullscreen Off");
                    screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);
                  break;
                  default:
                  break;
                }
              }
            break;
            default:
            break;
          }
          }

      break;
      default:
      break;
    }
  }
  //fps regulation
  SDL_Flip(screen);
  if(1000/fps>SDL_GetTicks()-start)
  {
  SDL_Delay( 1000/fps-(SDL_GetTicks()-start) );
  }
  }
  //outside of the menu cycle
  SDL_FreeSurface(bar);
  SDL_FreeSurface(barbg);
  SDL_FreeSurface(skelly);
  //SDL_FreeWAV(btnsnd);
  TTF_CloseFont(font);
  Mix_FreeChunk(btnsnd);
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_FreeSurface(image);
    for (int i=0;i<3;i++)
    {
      SDL_FreeSurface(text1[i]);
    }
  TTF_Quit();
  if(r == 0){
    SDL_QUIT;
  }
  return r;
}
int menu2(){

SDL_Surface *screen,*text1,*text2;
SDL_Rect pos1,pos2;
int cont=1;
SDL_Init( SDL_INIT_VIDEO );
TTF_Init();
screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE||SDL_DOUBLEBUF);
TTF_Font *font;
font=TTF_OpenFont("resources menu/souls_font.ttf",90);
SDL_Event event;
int mx,my;
SDL_Color red = {187, 0, 0},grey = {128,128,128};
pos1.x=100;
pos1.y=300;
pos2.x=600;
pos2.y=300;
int choix=0;

while(cont){
   SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
   if (choix==0){
    text1=TTF_RenderText_Blended(font,"Soloplayer",grey);
    text2=TTF_RenderText_Blended(font,"Multiplayer",grey);
    SDL_BlitSurface(text1,NULL,screen,&pos1);
    SDL_BlitSurface(text2,NULL,screen,&pos2);
      }
    else if (choix==1){
      text1=TTF_RenderText_Blended(font,"Soloplayer",red);
      text2=TTF_RenderText_Blended(font,"Multiplayer",grey);
      SDL_BlitSurface(text1,NULL,screen,&pos1);
      SDL_BlitSurface(text2,NULL,screen,&pos2);
      }
     else if (choix==2){
        text1=TTF_RenderText_Blended(font,"Soloplayer",grey);
        text2=TTF_RenderText_Blended(font,"Multiplayer",red);
        SDL_BlitSurface(text1,NULL,screen,&pos1);
        SDL_BlitSurface(text2,NULL,screen,&pos2);
      }

   while(SDL_PollEvent(&event))
   {
    switch(event.type){
      case SDL_QUIT:
      {
        cont = 0;
      }
      case SDL_MOUSEMOTION:
      mx=event.motion.x;
      my=event.motion.y;
      if ((mx>=pos1.x)&&(mx<=pos1.x+300)&&(my>=pos1.y)&&(my<=pos1.y+90)){
        choix=1;
      }
      else if ((mx>=pos2.x)&&(mx<=pos2.x+300)&&(my>=pos2.y)&&(my<=pos2.y+90)){
        choix=2;
      }
      else {
        choix=0;
      }
      break;
      case SDL_MOUSEBUTTONDOWN:
      if(event.button.button == SDL_BUTTON_LEFT)
      {
          if ((choix==1)||(choix==2))
          cont=0;
      }
      break;
      default:
      break;


    }
   } 



SDL_Flip(screen);
SDL_Delay(100);
} 


SDL_FreeSurface(text1);
SDL_FreeSurface(text2);
TTF_CloseFont(font);
TTF_Quit();
SDL_QUIT;

return choix;


}