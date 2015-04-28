
#define IMAGEN

//inlcueds externos
#include "SDL.h"

//includes de la libreria
#include "NewTypes.h"
#include "graphics.h"
#include "imagen.h"
//gero hobeto jarriko dugu
typedef struct Img
{
	int id;
	Imagen imagen;
	SDL_Rect dest;
}IMG;
//Variables privadas del modulo
//Imagen imagenes[MAX_IMG];
//SDL_Rect dest
IMG imagenes[MAX_IMG];
int numImagenes=0;
int id=0;

int insertaImagen(char *fileName)
{
	  //temp   = SDL_LoadBMP(”sprite.bmp”);
  //sprite = SDL_DisplayFormat(temp);
  //SDL_FreeSurface(temp);
	int colorkey;

	if (numImagenes< MAX_IMG)
	{
		imagenes[numImagenes].imagen = SDL_LoadBMP(fileName);
		if ( imagenes[numImagenes].imagen == NULL ) {
			fprintf(stderr, "Couldn't load %s: %s\n", fileName, SDL_GetError());
			 return -1;
		}
		else
		{
    		//dest[numImagenes] = 
			
			//dest[numImagenes].w=imagenes[numImagenes]->w;
			//dest[numImagenes].h=imagenes[numImagenes]->h;
			//SDL_SetColorKey( bitmap, SDL_SRCCOLORKEY, SDL_MapRGB(bitmap->format, 255, 0, 255) );
			//colorkey = SDL_MapRGB(imagenes[numImagenes]->format, 255, 0, 255);
			colorkey = SDL_MapRGB( imagenes[numImagenes].imagen->format, 255, 0, 255);
			SDL_SetColorKey(imagenes[numImagenes].imagen, SDL_SRCCOLORKEY, colorkey);
			imagenes[numImagenes].id = id;
			numImagenes++;
			id++;
		}
	}
	else
	{
		printf("Has superado el maixmo de Imagens por aplicación.Para aumentar imagen.h\n");
		return -1;
	}
	
	return id-1;//Esto hay que hacerlo con un hashmap. Cuando podamos
}

void  actualizaPosicionImagen( int numImg , int x, int y)
{

	int id=0;
	
	id =busquedaDePosicion(numImg);
	
	//dibujaImagen( imagenes[numImg], x, y);
	imagenes[id].dest.x = x;
    imagenes[id].dest.y = y;
    //dest[numImg].w= imagenes[numImg]->w;
	//dest[numImg].h= imagenes[numImg]->h;
	//
	
}

void pintaImagenes(void)
{
	int i=0;
	//igual tendremos que borrarlo
	//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	for (i=0; i<numImagenes ; i++)
		SDL_BlitSurface( imagenes[i].imagen ,  NULL, screen , &(imagenes[i].dest) );
	
}

void quitarImagen(int id)
{
	int i=0,pos=0;
	//Imagen img;
    //img = imagenes[id].imagen;
	//buscar por ID
	

	//SDL_FreeSurface(img);
	//SDL_FreeSurface(&dest[id]);

	pos=busquedaDePosicion(id);
	for ( i= pos ; i < numImagenes ; i++)
	{

		imagenes[i] = imagenes[i+1];
	}
	numImagenes--;
}

int busquedaDePosicion(int id)
{
	int i=0,buscado=0;

	while ( !buscado && i<numImagenes )
	{
		if ( id == imagenes[i].id)
		{
			buscado=1;
		}
		else
		{
			i++;
		}
	}
	
	return i;
}