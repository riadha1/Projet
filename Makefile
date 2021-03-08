menu: main.o menu.o
	gcc main.o menu.o -o menu -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image
main.o:main.c
	gcc -c main.c
menu.o:menu.c
	gcc -c menu.c
