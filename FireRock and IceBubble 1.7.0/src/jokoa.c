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
void JOKOA_lerroBBatMargotu(int x , int y , int x1, int y1, int kolorea);
void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1, int kolorea);
void JOKOA_sombreatua(int x, int y, int zabalera, int altuera);
void JOKOA_laukiBatMargotu(int x0, int y0, int x1, int y1, int kolorea);
void JOKOA_laukiBatMargotu3D(int x0, int y0, int x1, int y1, int kolorea);
//zentruaren x eta y puntuak
void JOKOA_diamanteBatMargotu(int x, int y, int kolorea);
//beheko ezker eskineko koordenadak
void JOKOA_ateBatMargotu(int x, int y, int kolorea);

void JOKOA_pelotaTxikia(int x, int y);


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
	//aldagaiak
	int x = 0, y = 0;

	//programa
	for (x = 0; x < 640; x++){
		for (y = 0; y < 480; y++){
			objetuak[x][y] = BELTZA;
		}
	}

	switch (pantaila){

	case 1:
		PANTAILA0_pantailaMargotu3D();
		PANTAILA0_pantailaMargotu();
		break;

	case 2:
		PANTAILA1_pantailaMargotu3D();
		PANTAILA1_pantailaMargotu();
		break;

	case 3:
		PANTAILA2_pantailaMargotu3D();
		PANTAILA2_pantailaMargotu();
		break;

	case 4:
		PANTAILA3_pantailaMargotu3D();
		PANTAILA3_pantailaMargotu();
		break;

	case 5:
		PANTAILA4_pantailaMargotu3D();
		PANTAILA4_pantailaMargotu();
		break;

	case 6:
		PANTAILA5_pantailaMargotu3D();
		PANTAILA5_pantailaMargotu();
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

void JOKOA_lerroBBatMargotu(int x , int y , int x1, int y1,int kolorea){
	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (yPantalla =y ; yPantalla < y1 ; yPantalla++  ){
		plot(x, yPantalla, kolorea);
		objetuak[x][yPantalla] = kolorea;
	}

}

void JOKOA_lerroHBatMargotu(int x , int y , int x1, int y1, int kolorea){

	double a= 0 , b = 0;
	int xPantalla = 0, yPantalla = 0;
	
	for (xPantalla =x ; xPantalla < x1 ; xPantalla++  ){
		plot(xPantalla, y, kolorea);
		objetuak[xPantalla][y] = kolorea;
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
			objetuak[i][t] = kolorea;
		}
	}

	//return
	return 0;
}

void JOKOA_laukiBatMargotu3D(int x0, int y0, int x1, int y1, int kolorea){
	//aldagaiak
	int i = 0;
	int t = 0;
	int w = 0;

	//programa
	for (i = x0; i < x1; i++){
		for (t = y0; t < y1; t++){
			for (w = 0; w < 5; w++){
				if ((i+w<=640)&&(i+w>0)&&(t-w<=480)&&(t-w>0)){
					plot(i + w, t - w, GRIS3);
				}
			}
		}
	}

	//return
	return 0;
}

//zentruaren x eta y puntuak
void JOKOA_diamanteBatMargotu(int x, int y, int kolorea){
	int lodiera = 0;
	//goiko zatia
	JOKOA_lerroHBatMargotu(x, y - 13, x, y - 13, kolorea);
	JOKOA_lerroHBatMargotu(x - 1, y - 12, x + 1, y - 12, kolorea);
	JOKOA_lerroHBatMargotu(x - 1, y - 11, x + 1, y - 11, kolorea);
	JOKOA_lerroHBatMargotu(x - 2, y - 10, x + 2, y - 10, kolorea);
	JOKOA_lerroHBatMargotu(x - 2, y - 9, x + 2, y - 9, kolorea);
	JOKOA_lerroHBatMargotu(x - 3, y - 8, x + 3, y - 8, kolorea);
	JOKOA_lerroHBatMargotu(x - 3, y - 7, x + 3, y - 7, kolorea);
	JOKOA_lerroHBatMargotu(x - 4, y - 6, x + 4, y - 6, kolorea);
	JOKOA_lerroHBatMargotu(x - 4, y - 5, x + 4, y - 5, kolorea);
	JOKOA_lerroHBatMargotu(x - 5, y - 4, x + 5, y - 4, kolorea);
	JOKOA_lerroHBatMargotu(x - 5, y - 3, x + 5, y - 3, kolorea);
	JOKOA_lerroHBatMargotu(x - 6, y - 2, x + 6, y - 2, kolorea);
	JOKOA_lerroHBatMargotu(x - 6, y - 1, x + 6, y - 1, kolorea);
	//erdiko lerroa
	JOKOA_lerroHBatMargotu(x - 7, y, x + 7, y, kolorea);
	//beheko zatia
	JOKOA_lerroHBatMargotu(x, y + 13, x, y + 13, kolorea);
	JOKOA_lerroHBatMargotu(x - 1, y + 12, x + 1, y + 12, kolorea);
	JOKOA_lerroHBatMargotu(x - 1, y + 11, x + 1, y + 11, kolorea);
	JOKOA_lerroHBatMargotu(x - 2, y + 10, x + 2, y + 10, kolorea);
	JOKOA_lerroHBatMargotu(x - 2, y + 9, x + 2, y + 9, kolorea);
	JOKOA_lerroHBatMargotu(x - 3, y + 8, x + 3, y + 8, kolorea);
	JOKOA_lerroHBatMargotu(x - 3, y + 7, x + 3, y + 7, kolorea);
	JOKOA_lerroHBatMargotu(x - 4, y + 6, x + 4, y + 6, kolorea);
	JOKOA_lerroHBatMargotu(x - 4, y + 5, x + 4, y + 5, kolorea);
	JOKOA_lerroHBatMargotu(x - 5, y + 4, x + 5, y + 4, kolorea);
	JOKOA_lerroHBatMargotu(x - 5, y + 3, x + 5, y + 3, kolorea);
	JOKOA_lerroHBatMargotu(x - 6, y + 2, x + 6, y + 2, kolorea);
	JOKOA_lerroHBatMargotu(x - 6, y + 1, x + 6, y + 1, kolorea);

}

//atearen beheko ezkerreko muturra
void JOKOA_ateBatMargotu(int x, int y, int kolorea){

	int lodiera = 0;

	JOKOA_lerroHBatMargotu(x + 2, y - 61, x + 43, y - 59, kolorea);
	JOKOA_lerroHBatMargotu(x + 1, y - 60, x + 44, y - 58, kolorea);
	for (lodiera = 2; lodiera < 60; lodiera++){
		JOKOA_lerroHBatMargotu(x, y - lodiera, x + 45, y - lodiera, kolorea);
	}
	JOKOA_lerroHBatMargotu(x + 1, y - 1, x + 44, y - 1, kolorea);
	JOKOA_lerroHBatMargotu(x + 2, y, x + 43, y, kolorea);

}

void JOKOA_pelotaTxikia(int x, int y){
	int ilara = 0, zutabea = 0;

	for (ilara = -5; ilara < 5; ilara++){
		for (zutabea = -5; zutabea < 5; zutabea++){
			if ((ilara*ilara) + (zutabea*zutabea) <= (5 * 5)){
				plot(x + zutabea, y + ilara, HARRI_KOLOREA);
				objetuak[x + zutabea][y + ilara] = HARRI_KOLOREA;
			}
		}
	}
}