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


void PANTAILA5_pantailaMargotu();


int PANTAILA5_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	
	//aldagaiak
	int aukera = 2;

	//programa

	do{

		posizioGorria.x = 90;
		posizioGorria.y = 450 - ERRADIOBOLA;

		posizioUrdina.x = 90;
		posizioUrdina.y = 349 - ERRADIOBOLA;

		do{

			aukera = ERREALITATE_FISIKOA_mugimendua(4);

		} while (aukera == 1);

	} while (aukera == 2);

	//return
	return 1;

}

void PANTAILA5_pantailaMargotu(){
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


	//erdiko plataformak 
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 350, 110, 380, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(550, 350, 640, 380, BERDE_ILUNA);
	//erdikoa
	JOKOA_laukiBatMargotu(230, 350, 450, 380, BERDE_ILUNA);

	//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 100, 230, 130, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(400, 100, 640, 130, BERDE_ILUNA);

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu(440, 100, 540, 110, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(90, 100, 190, 110, URDINA);

	//harria

	JOKOA_laukiBatMargotu(370, 300, 420, 350, HARRI_KOLOREA);

	//ateak
	//urdina
	JOKOA_ateBatMargotu(574, 99, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(20, 99, GORRIA2);
//goikoa plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(595, 360, 615, 370, MOREA_BOTOIA1);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(320, 100, 400, 115, MOREA_PLATAFORMA1);

//behekoa plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(495, 440, 515, 450, MOREA_BOTOIA2);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(200, 335, 280, 350, MOREA_PLATAFORMA2);

}