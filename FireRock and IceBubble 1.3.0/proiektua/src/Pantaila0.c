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


int PANTAILA0_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	//programa
	posizioGorria.x = 50;
	posizioGorria.y = 468 - ERRADIOBOLA;

	posizioUrdina.x = 50 + 10 + ERRADIOBOLA + ERRADIOBOLA;
	posizioUrdina.y = 468 - ERRADIOBOLA;

	ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina,1);

	//return
	return 1;

}

void PANTAILA0_pantailaMargotu(){
	//aldagaiak
	int x = 0, y = 0;

	//programa
	

	//goiko lerroa
	JOKOA_laukiBatMargotu(0, 0, 639, 9, BERDE_ILUNA);

	//beheko lerroa
	JOKOA_laukiBatMargotu(0, 469, 639, 479, BERDE_ILUNA);
	

	//ezkerreko lerroa
	JOKOA_laukiBatMargotu(0, 0, 9, 479, BERDE_ILUNA);
	

	//eskumako lerroa
	JOKOA_laukiBatMargotu(629, 0, 639, 479, BERDE_ILUNA);
	
	

	//1.eskaloia
	JOKOA_laukiBatMargotu(149, 429, 349, 469, BERDE_ILUNA);


	//2.eskaloia
	JOKOA_laukiBatMargotu(199, 389, 299, 429, BERDE_ILUNA);
	

	//3.eskaloia
	JOKOA_laukiBatMargotu(399, 369, 499, 399, BERDE_ILUNA);
	
	//Ate Urdina
	JOKOA_ateBatMargotu(430, 368, URDINA2);

	//Ate Gorria
	JOKOA_ateBatMargotu(550, 469, GORRIA2);
}