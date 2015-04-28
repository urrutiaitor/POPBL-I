#ifndef GRAPHICS
	#define PUB_GRAPHICS extern
#else
	#define PUB_GRAPHICS 
#endif

PUB_GRAPHICS SDL_Surface *screen;

int inicializaSistemaGrafico();//Sin opciones
int finalizaSistemaGrafico();//Sin opciones
void plot(int x, int y, int color);
int dibujaImagen(Imagen imagen, int x, int y);//hay qu definir como hacerlo, ya veremos si es con doble bufgfer o no
int borraCopiaPantalla();
void actualizaPantalla();

//escucha de pulsados




//Macro para varibales globales externs
