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


void PANTAILA2_pantailaMargotu();


int PANTAILA2_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	int amaituta;


	//programa
	posizioGorria.x = 50;
	posizioGorria.y = 449 - ERRADIOBOLA;

	posizioUrdina.x = 50 ;
	posizioUrdina.y = 259 - ERRADIOBOLA;
	PANTAILA2_pantailaMargotu();
	 ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina, 3);


	//return
	return 1;

}

void PANTAILA2_pantailaMargotu(){
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



	//erdiko plataforma
	//erdikoa
	JOKOA_laukiBatMargotu(320, 170, 550, 200, BERDE_ILUNA);
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0,260 , 330,290 , BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(410, 260, 640, 290, BERDE_ILUNA);

	//goiko plataforma
	JOKOA_laukiBatMargotu(0, 90, 290, 120, BERDE_ILUNA);


//putzuak
	//gorria
	JOKOA_laukiBatMargotu(160, 260, 260, 270, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(160, 450, 260, 460, URDINA);

	//berdea
	JOKOA_laukiBatMargotu(385, 170, 485, 180, BERDEA);

//diamanteak
	//gorria
	JOKOA_diamanteBatMargotu(590, 240, GORRIA);
	//urdina
	JOKOA_diamanteBatMargotu(300, 430, URDINA);


//ateak
	//urdina
	JOKOA_ateBatMargotu(20, 89, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(575, 449, GORRIA2);

//plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(120, 250, 140, 260, MOREA);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(330, 260, 410, 275, MOREA);



}
