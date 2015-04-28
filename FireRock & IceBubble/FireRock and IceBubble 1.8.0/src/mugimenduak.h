#ifndef KONTROLAK
#define KONTROLAK

#include "SDL.h"
#include<stdio.h>
#define W 119
#define A 97
#define S 115
#define D 100
#define ENTER 13

#ifndef BOOLEANS
#define BOOLEANS
typedef enum{
	FALSE, TRUE
}BOOLEAN;
#endif

typedef struct {
	BOOLEAN Rarrow;
	BOOLEAN Larrow;
	BOOLEAN Uarrow;
	BOOLEAN Darrow;
	BOOLEAN w;
	BOOLEAN a;
	BOOLEAN s;
	BOOLEAN d;
	BOOLEAN intro;
} KB;

typedef struct {
	KB keyboard;
} C;

SDL_Event event;
C actualizaControles ( C controls );
void kontrolakBistaratu ( C controls );

#endif