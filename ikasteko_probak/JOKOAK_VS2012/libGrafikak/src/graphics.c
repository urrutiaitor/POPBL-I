//Esto con un incude de include
#include <stdlib.h>
#include <stdio.h>


#define GRAPHICS

#include "SDL.h"
#include "SDL_ttf.h"

#include "NewTypes.h"
#include "imagen.h"
#include "graphics.h"



int lineoffset;

int inicializaSistemaGrafico()
{
  int ret=0;

  if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
  {
    fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
    ret = -1;//esto igual hay que ponerlo mejor
	return ret;
  }
  // Register SDL_Quit to be called at exit; makes sure things are
  // cleaned up when we quit.
  atexit(SDL_Quit);
   // Attempt to create a 640x480 window with 32bit pixels.
  //screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
  screen = SDL_SetVideoMode(640, 480, 32, 0);
  // If we fail, return error.
  if ( screen == NULL ) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
	ret = -1;
  }
  else
  {
	lineoffset = ( screen->pitch / ( screen->format->BytesPerPixel) );
  }
    TTF_Init();
      atexit(TTF_Quit);
  return ret;
}
int finalizaSistemaGrafico()
{
	return 0;
}

void plot(int x, int y, int color)
{
  unsigned int *ptr = (unsigned int*)screen->pixels;
  int j;
  //Lock surface if needed
  if (SDL_MUSTLOCK(screen)) 
   if (SDL_LockSurface(screen) < 0) 
     return;
  //***************************************Lock if needed
  j = y * lineoffset;
  ptr[ j + x] = color;
  //****************************** Unlock if needed
 if (SDL_MUSTLOCK(screen)) 
   SDL_UnlockSurface(screen);
  // Tell SDL to update the whole screen
 
}
int dibujaImagen(Imagen imagen , int x , int y )
{
	SDL_Rect dest;

	dest.x = x;
    dest.y = y;
    dest.w = imagen->w;
    dest.h = imagen->h;

	SDL_BlitSurface(imagen, NULL, screen, &dest);
}
int borraCopiaPantalla()
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}

void actualizaPantalla()
{
	//SDL_UpdateRect(screen, 0, 0, 640, 480);  // esto realintza bastante
	//SDL_UpdateRect(screen, 0, 0, 640, 480);
	 SDL_Flip(screen);
}