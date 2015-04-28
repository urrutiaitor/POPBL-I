
//Una apliaccaión podra tener como maximo un numero de participantes aunque habra que hacerlo conuna lista enlzada 

#ifndef IMAGEN
	#define PUB_GRAPHICS extern
#else
	#define PUB_GRAPHICS 
#endif



//Constantes de modulo. Esto es configuracion
#define MAX_IMG 100



//Variables Publicas de modulo

//PUB_GRAPHICS Imagen imagenes[MAX_IMG];

//Funciones
int  insertaImagen(char *fileName);
void  actualizaPosicionImagen(int numImg, int x, int y);
void pintaImagenes(void);
void quitarImagen(int id);
int busquedaDePosicion(int id);



