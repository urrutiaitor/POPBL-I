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
	for (x = 0; x < 640; x++){
		for (y = 0; y < 480; y++){
			objetuak[x][y] = 0;
		}
	}

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