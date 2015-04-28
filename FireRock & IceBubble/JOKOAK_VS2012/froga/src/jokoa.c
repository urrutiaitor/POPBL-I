#include "orokorrak.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"

//LIBRERIA GARFIKOA
#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
//LIBRERIA MATEMATIKOA
#include "math.h"


int JOKOA_jokalariaIrudiaSortu();
void JOKOA_zirkuluaBistaratu( int xRef , int yRef);
void JOKOA_zelaiaMargotu();
void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1);
void JOKOA_lerroVBatMargotu(int x , int y , int x1, int y1);


EGOERA JOKOA_jokoa(){
	BOOLEAN mugitu = FALSE;
	EGOERA  egoera=JOLASTEN;
	int tekla = 0;
	int idAudio = -1, idAudioWin = -1, idAudioLoose = -1, idIrudia=-1;
	JOKO_ELEMENTUA zirkulua, jokalaria;
	POSIZIOA aux;
	zirkulua.pos.x = 200;
	zirkulua.pos.y = 200;
	
	jokalaria.pos.x = 0;
	jokalaria.pos.y = 200;
	
	idAudio = playAudio(JOKOA_SOUND,  0);
	jokalaria.id =JOKOA_jokalariaIrudiaSortu();
	do{
		aux = ERREALITATE_FISIKOA_mugimendua(zirkulua.pos);
		zirkulua.pos.y = aux.y;
		borraCopiaPantalla();
		JOKOA_zelaiaMargotu();
		JOKOA_zirkuluaBistaratu(zirkulua.pos.x, zirkulua.pos.y);
		actualizaPosicionImagen( jokalaria.id, jokalaria.pos.x , jokalaria.pos.y); 
		pintaImagenes();
		actualizaPantalla();
		tekla = ebentoaEntzun();
		if (tekla == SAGU_BOTOIA_ESKUMA || tekla== SAGU_BOTOIA_EZKERRA ){
			mugitu = TRUE;
		}
		if (zirkulua.pos.y + 30 > 478){
			zirkulua.pos.y = 0 +30;
		}
		if (mugitu){
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x;
		}
		egoera = JOKOA_egoera(jokalaria, zirkulua);
	}while( egoera   == JOLASTEN);

	
	removeAudio(idAudio);
	removeAudio(idAudioWin);
	removeAudio(idAudioLoose);
	quitarImagen(jokalaria.id);
	borraCopiaPantalla();
	actualizaPantalla();
	return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria , JOKO_ELEMENTUA oztopoa){
	EGOERA  ret = JOLASTEN;
	if (jokalaria.pos.x >oztopoa.pos.x-20 &&  jokalaria.pos.x <oztopoa.pos.x+20 && jokalaria.pos.y >oztopoa.pos.y-20 && jokalaria.pos.y <oztopoa.pos.y+20 ){
		ret = IRABAZI;
	}else if (jokalaria.pos.x > 600 ){
			ret = GALDU;
	}
	return ret;
}

int JOKOA_jokalariaIrudiaSortu(){
	int martzianoId = -1;
	martzianoId= insertaImagen(JOKOA_PLAYER_IMAGE);
	actualizaPosicionImagen( martzianoId, 10 , 239); 
	borraCopiaPantalla();
	pintaImagenes();
	actualizaPantalla();
	return martzianoId;

}

void JOKOA_zirkuluaBistaratu(int xRef , int yRef){
	double x = 0, y = 0, r = 20;
	double delta=0.01, deltaR=1;
	double rIni = 0;
	int i = 0;
	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;

	
	
	//Esta condicion da guerra
	while (rIni < r){
		x = -rIni;
		//No pinta el primer punto ni el ultimo
		//printf("Otra circuneferencia  radio=%f \n",rIni);
		//printf("**********************\n");
		while(x < rIni+delta){
			y = (rIni*rIni)  - ( (x-a)*(x-b) );
			y = sqrt(  y  );
			//printf("x=%f y=%f\n",x ,y  );
			xPantalla = (int) (xRef + (i) + x);
			yPantalla = (int) (yRef + y);
			plot( xPantalla , yPantalla ,170);
			yPantalla = (int) (yRef + (-1)*y);
			plot( xPantalla , yPantalla ,170);
			x = x + delta;
		}
		rIni = rIni + deltaR;
	}
	xPantalla = (int) (xRef + (-10));
	yPantalla = (int) (yRef + 0 );
	plot( xPantalla , yPantalla ,170);

}

void JOKOA_zelaiaMargotu(){
	//Esta condicion da guerra
	JOKOA_lerroHBatMargotu (0,0 , 0, 479);
	JOKOA_lerroVBatMargotu( 0,0 , 639, 0);
	JOKOA_lerroVBatMargotu(0,479, 639,479);
	JOKOA_lerroHBatMargotu(639,0, 639,479);	
}

void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1){
	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (yPantalla =y ; yPantalla < y1 ; yPantalla++  ){
		plot( x , yPantalla ,170);
	}

}

void JOKOA_lerroVBatMargotu(int x , int y , int x1, int y1){

	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (xPantalla =x ; xPantalla < x1 ; xPantalla++  ){
		plot( xPantalla , y ,170);
	}


}