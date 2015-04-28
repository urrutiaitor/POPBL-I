#include "orokorrak.h"
#include "Pantaila0.h"
#include "jokoa.h"
#include "errealitateFisikoa.h"

//LIBRERIA GARFIKOA
#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
//LIBRERIA MATEMATIKOA
#include "math.h"


void PANTAILA0_pantailaMargotu();
int PANTAILA0_pantailakoObjetuakKonprobatu(POSIZIOA bolarenPosizioa);

int PANTAILA0_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	//programa
	posizioGorria.x = 50;
	posizioGorria.y = 469 - ERRADIOBOLA;

	posizioUrdina.x = 50 + 10 + ERRADIOBOLA + ERRADIOBOLA;
	posizioUrdina.y = 469 - ERRADIOBOLA;

	ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina,1);

	//return
	return 1;

}

void PANTAILA0_pantailaMargotu(){
	//aldagaiak
	int x = 0, y = 0;

	//programa

	//goiko lerroa
	JOKOA_laukiBatMargotu(0, 0, 640, 10, ZURIA);
	
	//beheko lerroa
	JOKOA_laukiBatMargotu(0, 470, 640, 480, ZURIA);

	//ezkerreko lerroa
	JOKOA_laukiBatMargotu(0, 0, 10, 480, ZURIA);

	//eskumako lerroa
	JOKOA_laukiBatMargotu(630, 0, 640, 480, ZURIA);

	//1.eskaloia
	JOKOA_laukiBatMargotu(149, 429, 350, 470, ZURIA);

	//2.eskaloia
	JOKOA_laukiBatMargotu(199, 389, 300, 430, ZURIA);

	//3.eskaloia
	JOKOA_laukiBatMargotu(399, 369, 500, 400, ZURIA);
}

int PANTAILA0_pantailakoObjetuakKonprobatu(int x0,int y0){
	//aldagaiak
	int x = 0, y = 0;
	int objetua = BELTZA;

	//programa

	//goiko lerroa
	if ((x0 >= 0) && (x0 <= 640) && (y0 > 0) && (y0 <= 10)){
		objetua = ZURIA;
	}

	//beheko lerroa
	if ((x0 >= 0) && (x0 <= 640) && (y0 > 470) && (y0 <= 480)){
		objetua = ZURIA;
	}

	//ezkerreko lerroa
	if ((x0 >= 0) && (x0 <= 10) && (y0 >= 0) && (y0 <= 480)){
		objetua = ZURIA;
	}

	//eskumako lerroa
	if ((x0 >= 630) && (x0 <= 640) && (y0 >= 0) && (y0 <= 480)){
		objetua = ZURIA;
	}

	//1.eskaloia
	if ((x0 >= 150) && (x0 <= 350) && (y0 >= 430) && (y0 <= 470)){
		objetua = ZURIA;
	}

	//2.eskaloia
	if ((x0 >= 200) && (x0 <= 300) && (y0 >= 390) && (y0 <= 430)){
		objetua = ZURIA;
	}

	//3.eskaloia
	if ((x0 >= 400) && (x0 <= 500) && (y0 >= 370) && (y0 <= 400)){
		objetua = ZURIA;
	}

	//return
	return objetua;
}