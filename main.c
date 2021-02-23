#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
//#include "header.h"

void setrects(SDL_Rect clips[12][8])
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


int main(int argc, char** argv)
{
    TTF_Init();
    int quit = 0;
    int frame=0;
    int framej=0;
    Uint32 start;
    const int fps=30;
    TTF_Font *font=NULL;
    char a[3][10];
    strcpy (a[0],"Play");
    strcpy (a[1],"Settings");
    strcpy (a[2],"Exit");
    char b[3][20];
    strcpy (b[0],"Volume");
    strcpy (b[1],"Fullscreen On");
    strcpy (b[2],"Back To Menu");
    SDL_Surface *text1[3],*text2[3],*image,*screen;
    SDL_Rect offset,postext;
    SDL_Event event;
    SDL_Color white={255,255,255},red = {187, 0, 0};
    font=TTF_OpenFont("souls_font.ttf",90);
    offset.x = 0;
    offset.y = 0;
    int mx,my;
//    if(Mix_OpenAudio(88200,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  //   	{
	//	printf("audio no can do %s\n",Mix_GetError());
	 //   }
	Mix_Music *music;
  Mix_Chunk *btnsnd;
  Mix_OpenAudio(88200,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
  btnsnd=Mix_LoadWAV("btnsnd.wav");
	music=Mix_LoadMUS("mainmenu.mp3");
	Mix_PlayMusic(music,-1);

    if( TTF_Init() == -1 ) //ktiba
    {
        printf( "Can't TTF:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }
    if(font==NULL) //ktiba
    {
        printf( "Can't font bruh:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }
	offset.x = 0;
	offset.y = 0;
    if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    {
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }




    screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);//| SDL_RESIZABLE); );

    if( screen == NULL )
    {
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }
    image=IMG_Load("1.png");
    SDL_Rect rects[12][8];
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
	int FS = 1;
	while(quit == 0)
  {
    //background render+get ticks
    SDL_BlitSurface(image,&rects[framej][frame],screen,&offset);
    //SDL_Flip(screen);
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
    //text render
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
				else
        {
					text2[i]=TTF_RenderText_Blended(font,b[i],white);
				}
			}
			postext.x=310;
			postext.y=440+i*100;
			SDL_BlitSurface(text2[i], NULL,screen,&postext);
			}
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
          if ((mx>=postext.x)&&(mx<=postext.x+250)&&(my>=440)&&(my<=440+70))
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
          switch(sett){
            case 0:
              if(m == 1)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                sett = 1;
                SDL_FreeSurface(text1[0]);
                SDL_FreeSurface(text1[1]);
                SDL_FreeSurface(text1[2]);
              }
              if(m == 2)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                quit = 1;
              }
            break;
            case 1:
              if(m == 2)
              {
                Mix_PlayChannel(-1, btnsnd, 0);
                sett = 0;
                SDL_FreeSurface(text2[0]);
                SDL_FreeSurface(text2[1]);
                SDL_FreeSurface(text2[2]);
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
          break;
        }
        else break;
      }
				case SDL_QUIT:
        {
          TTF_CloseFont(font);
          Mix_FreeChunk(btnsnd);
          Mix_FreeMusic(music);
          Mix_CloseAudio();
          SDL_FreeSurface(image);
          for (int i=0;i<3;i++)
          {
            SDL_FreeSurface(text1[i]);
            SDL_FreeSurface(text2[i]);
          }
          SDL_FreeSurface(screen);
					quit = 1;
				}
				break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE)
          {
					quit = 1;
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
					if(event.key.keysym.sym == SDLK_RETURN)
          {
						switch(sett)
            {
							case 0:
								if(m == 1)
                {
                  Mix_PlayChannel(-1, btnsnd, 0);
									sett = 1;
									SDL_FreeSurface(text1[0]);
    							SDL_FreeSurface(text1[1]);
    							SDL_FreeSurface(text1[2]);
								}
								if(m == 2)
                {
									quit = 1;
								}
							break;
							case 1:
								if(m == 2)
                {
                  Mix_PlayChannel(-1, btnsnd, 0);
									sett = 0;
									SDL_FreeSurface(text2[0]);
    							SDL_FreeSurface(text2[1]);
    							SDL_FreeSurface(text2[2]);
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
						//SDL_BlitSurface(image, &rects[framej][frame], screen, &offset);
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
    TTF_CloseFont(font);
    Mix_FreeChunk(btnsnd);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_FreeSurface(image);
    for (int i=0;i<3;i++)
    {
      SDL_FreeSurface(text1[i]);
      SDL_FreeSurface(text2[i]);
    }
    SDL_FreeSurface(screen);
    SDL_Quit();
    return EXIT_SUCCESS;
}
