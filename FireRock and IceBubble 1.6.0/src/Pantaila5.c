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
		//harria
		ostopoak[0].kolorea = HARRI_KOLOREA;
		ostopoak[0].x0 = 370;
		ostopoak[0].y0 = 300;
		ostopoak[0].x1 = 420;
		ostopoak[0].y1 = 350;

		//goikoa plataforma mugikorra
		//botoia
		ostopoak[1].kolorea = MOREA_BOTOIA1;
		ostopoak[1].x0 = 595;
		ostopoak[1].y0 = 350;
		ostopoak[1].x1 = 615;
		ostopoak[1].y1 = 360;

		//plataforma mugikorra
		ostopoak[2].kolorea = MOREA_PLATAFORMA1;
		ostopoak[2].x0 = 320;
		ostopoak[2].y0 = 200;
		ostopoak[2].x1 = 400;
		ostopoak[2].y1 = 215;

		//behekoa plataforma mugikorra
		//botoia
		ostopoak[3].kolorea = MOREA_BOTOIA2;
		ostopoak[3].x0 = 495;
		ostopoak[3].y0 = 440;
		ostopoak[3].x1 = 515;
		ostopoak[3].y1 = 450;
		
		//plataforma mugikorra
		ostopoak[4].kolorea = MOREA_PLATAFORMA2;
		ostopoak[4].x0 = 200;
		ostopoak[4].y0 = 335;
		ostopoak[4].x1 = 280;
		ostopoak[4].y1 = 350;
	
		posizioGorria.x = 90;
		posizioGorria.y = 450 - ERRADIOBOLA;

		posizioUrdina.x = 90;
		posizioUrdina.y = 349 - ERRADIOBOLA;

		do{

			aukera = ERREALITATE_FISIKOA_mugimendua(6);

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
	JOKOA_laukiBatMargotu(0, 360, 110, 390, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(550, 360, 640, 390, BERDE_ILUNA);
	//erdikoa
	JOKOA_laukiBatMargotu(230, 350, 450, 380, BERDE_ILUNA);

	//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 100, 230, 130, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(400, 200, 640, 230, BERDE_ILUNA);

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu(440, 200, 540, 210, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(90, 100, 190, 110, URDINA);

	//harria

	JOKOA_laukiBatMargotu(ostopoak[0].x0, ostopoak[0].y0, ostopoak[0].x1, ostopoak[0].y1, ostopoak[0].kolorea);
//ateak
	//urdina
	JOKOA_ateBatMargotu(574, 199, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(20, 99, GORRIA2);
//goikoa plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(ostopoak[1].x0, ostopoak[1].y0, ostopoak[1].x1, ostopoak[1].y1, ostopoak[1].kolorea);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(ostopoak[2].x0, ostopoak[2].y0, ostopoak[2].x1, ostopoak[2].y1, ostopoak[2].kolorea);

//behekoa plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(ostopoak[3].x0, ostopoak[3].y0, ostopoak[3].x1, ostopoak[3].y1, ostopoak[3].kolorea);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(ostopoak[4].x0, ostopoak[4].y0, ostopoak[4].x1, ostopoak[4].y1, ostopoak[4].kolorea);

}