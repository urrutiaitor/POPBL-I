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


void PANTAILA1_pantailaMargotu();


int PANTAILA1_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;
	
	int amaituta;


	//programa
	posizioGorria.x = 50;
	posizioGorria.y = 449 - ERRADIOBOLA;

	posizioUrdina.x = 50 + 10 + ERRADIOBOLA + ERRADIOBOLA;
	posizioUrdina.y = 449 - ERRADIOBOLA;
	PANTAILA1_pantailaMargotu();
	ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina, 2);


	//return
	return 1;

}

void PANTAILA1_pantailaMargotu(){
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
	JOKOA_laukiBatMargotu(0, 300, 510, 330, BERDE_ILUNA);


	//goiko plataforma
	JOKOA_laukiBatMargotu(250, 150, 640, 180, BERDE_ILUNA);
	

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu(160, 450, 260, 460, GORRIA);
	
	//urdina
	JOKOA_laukiBatMargotu(330, 450, 430, 460, URDINA);

	//berdea
	JOKOA_laukiBatMargotu(300, 150, 400, 160, BERDEA);

	//harriak
	//behekoa
	JOKOA_laukiBatMargotu(550, 400, 600, 450, HARRI_KOLOREA);

	//erdiko plataformakoa
	JOKOA_laukiBatMargotu(60, 250, 110, 300, HARRI_KOLOREA);
	

	//ateak
	//urdina
	 JOKOA_ateBatMargotu(530, 149, URDINA2);

	//gorria
	 JOKOA_ateBatMargotu(585, 149, GORRIA2);



}