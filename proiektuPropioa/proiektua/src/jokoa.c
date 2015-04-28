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


void JOKOA_zirkuluaBistaratu( int xRef , int yRef, int kolorea);
void JOKOA_zirkuluGorriaBistaratu(int xRef, int yRef);
void JOKOA_zelaiaMargotu();
int JOKOA_zelaiaKonprobatu(POSIZIOA posizioGorria, POSIZIOA posizioUrdina);
void JOKOA_pantailaZuriz();
void JOKOA_lerroBBatMargotu(int x , int y , int x1, int y1);
void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1);
void JOKOA_sombreatua(int x, int y, int zabalera, int altuera);
void JOKOA_laukiBatMargotu(int x0, int y0, int x1, int y1, int kolorea);


EGOERA JOKOA_jokoa(){
	//aldagaiak
	BOOLEAN mugitu = FALSE;
	EGOERA egoera = JOLASTEN;
	int tekla = 0;

	//programa

	//return
	return egoera;
}

void JOKOA_zirkuluaBistaratu(int xRef, int yRef, int kolorea){

	int ilara = 0, zutabea = 0;

	for (ilara = -ERRADIOBOLA; ilara <= ERRADIOBOLA; ilara++){
		for (zutabea = -ERRADIOBOLA; zutabea <= ERRADIOBOLA; zutabea++){
			if ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA)){
				plot(xRef + zutabea, yRef + ilara, kolorea);
				
				
			}
		}
	}
}

void JOKOA_zelaiaMargotu(int pantaila){
	JOKOA_pantailaZuriz();

	switch (pantaila){

	case 1:
		PANTAILA0_pantailaMargotu();
		break;

	case 2:

		break;

	case 3:

		break;

	case 4:

		break;

	case 5:

		break;
	}
	
}

void JOKOA_pantailaZuriz(){
	//aldagaiak
	int i = 0;
	int t = 0;

	//programa
	for (i = 0; i < 480; i++){
		for (t = 0; t < 640; t++){
			plot(t, i, ZURIA);
		}
	}
}

void JOKOA_lerroBBatMargotu(int x , int y , int x1, int y1){
	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (yPantalla =y ; yPantalla < y1 ; yPantalla++  ){
		plot(x, yPantalla, BELTZA);
	}

}

void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1){

	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (xPantalla =x ; xPantalla < x1 ; xPantalla++  ){
		plot(xPantalla, y, BELTZA);
	}


}

void JOKOA_laukiBatMargotu(int x0, int y0, int x1, int y1, int kolorea){
	//aldagaiak
	int i = 0;
	int t = 0;

	//programa
	for (i = x0; i < x1; i++){
		for (t = y0; t < y1; t++){
			plot(i, t, kolorea);
		}
	}

	//return
	return 0;
}