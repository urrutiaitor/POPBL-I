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


void PANTAILA0_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	int aukera = 2;

	//programa

	do{

		posizioGorria.x = 50;
		posizioGorria.y = 468 - ERRADIOBOLA;

		posizioUrdina.x = 50 + 10 + ERRADIOBOLA + ERRADIOBOLA;
		posizioUrdina.y = 468 - ERRADIOBOLA;

		do{

			aukera=ERREALITATE_FISIKOA_mugimendua(1);

		} while (aukera == 1);

	} while (aukera == 2);

	//return
	return 1;

}

void PANTAILA0_pantailaMargotu(){
	
	//goiko lerroa
	JOKOA_laukiBatMargotu(0, 0, 640, 10, BERDE_ILUNA);

	//beheko lerroa
	JOKOA_laukiBatMargotu(0, 470, 640, 480, BERDE_ILUNA);
	

	//ezkerreko lerroa
	JOKOA_laukiBatMargotu(0, 0, 10, 480, BERDE_ILUNA);
	

	//eskumako lerroa
	JOKOA_laukiBatMargotu(629, 0, 640, 480, BERDE_ILUNA);
	
	

	//1.eskaloia
	JOKOA_laukiBatMargotu(149, 430, 349, 470, BERDE_ILUNA);


	//2.eskaloia
	JOKOA_laukiBatMargotu(199, 390, 299, 430, BERDE_ILUNA);
	

	//3.eskaloia
	JOKOA_laukiBatMargotu(399, 369, 499, 399, BERDE_ILUNA);
	
	//Ate Urdina
	JOKOA_ateBatMargotu(430, 368, URDINA2);

	//Ate Gorria
	JOKOA_ateBatMargotu(550, 469, GORRIA2);
}