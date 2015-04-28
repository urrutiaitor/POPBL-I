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

#define ERRADIOBOLA 20


void PANTAILA3_pantailaMargotu();


int PANTAILA3_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	int amaituta;


	//programa
	posizioGorria.x = 590;
	posizioGorria.y = 79 - ERRADIOBOLA;

	posizioUrdina.x = 50 ;
	posizioUrdina.y = 99 - ERRADIOBOLA;
	PANTAILA3_pantailaMargotu();
	ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina, 4);


	//return
	return 1;

}

void PANTAILA3_pantailaMargotu(){
	//aldagaiak
	int x = 0, y = 0;


	//programa


	//goiko lerroa
	JOKOA_laukiBatMargotu(0, 0, 640, 10, BERDE_ILUNA);

	//beheko lerroa
	JOKOA_laukiBatMargotu(0, 450, 640, 480, BERDE_ILUNA);


	//ezkerreko lerroa
	JOKOA_laukiBatMargotu(0, 0, 10, 480, BERDE_ILUNA);


	//eskumako lerroa
	JOKOA_laukiBatMargotu(630, 0, 640, 480, BERDE_ILUNA);


	//erdiko plataformaK 
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 300, 250, 330, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(510, 300, 640, 330, BERDE_ILUNA);
	//luzea
	JOKOA_laukiBatMargotu(150, 200, 640, 230, BERDE_ILUNA);
	//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 100, 230, 130, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(400, 80, 640, 110, BERDE_ILUNA);

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu(100, 100, 200,110, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(90, 450, 190, 460, URDINA);

	//berdea
	JOKOA_laukiBatMargotu(440, 200, 540, 210, BERDEA);

	//harria
	
	JOKOA_laukiBatMargotu(150, 250, 200, 300, HARRI_KOLOREA);

	//diamanteak
	//gorria
	JOKOA_diamanteBatMargotu(150, 80, GORRIA);
	//urdina
	JOKOA_diamanteBatMargotu(550, 60, URDINA);


	//ateak
	//urdina
	JOKOA_ateBatMargotu(585-10, 299, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(20, 449, GORRIA2);

	//botoia
	JOKOA_laukiBatMargotu(590, 190, 610, 200, MOREA);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(275, 185, 355, 200, MOREA);

}