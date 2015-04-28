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


void PANTAILA2_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona

	//aldagaiak
	int aukera = 2;

	//programa

	do{

		posizioGorria.x = 50;
		posizioGorria.y = 449 - ERRADIOBOLA;

		posizioUrdina.x = 50;
		posizioUrdina.y = 259 - ERRADIOBOLA;

		//putzuak
		//gorria
		ostopoak[0].kolorea = GORRIA;
		ostopoak[0].x0 = 160;
		ostopoak[0].y0 = 260;
		ostopoak[0].x1 = 260;
		ostopoak[0].y1 = 270;
		
		//urdina
		ostopoak[1].kolorea = URDINA;
		ostopoak[1].x0 = 160;
		ostopoak[1].y0 = 450;
		ostopoak[1].x1 = 260;
		ostopoak[1].y1 = 460;

		//berdea
		ostopoak[2].kolorea = BERDEA;
		ostopoak[2].x0 = 385;
		ostopoak[2].y0 = 170;
		ostopoak[2].x1 = 485;
		ostopoak[2].y1 = 180;

		//plataforma mugikorra
		//botoia
		ostopoak[3].kolorea = MOREA_BOTOIA1;
		ostopoak[3].x0 = 120;
		ostopoak[3].y0 = 250;
		ostopoak[3].x1 = 140;
		ostopoak[3].y1 = 260;

		//plataforma mugikorra
		ostopoak[4].kolorea = MOREA_PLATAFORMA1;
		ostopoak[4].x0 = 330;
		ostopoak[4].y0 = 260;
		ostopoak[4].x1 = 410;
		ostopoak[4].y1 = 275;

		do{

			aukera = ERREALITATE_FISIKOA_mugimendua(3);

		} while (aukera == 1);

	} while (aukera == 2);

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
	JOKOA_laukiBatMargotu(ostopoak[0].x0, ostopoak[0].y0, ostopoak[0].x1, ostopoak[0].y1, ostopoak[0].kolorea);

	//urdina
	JOKOA_laukiBatMargotu(ostopoak[1].x0, ostopoak[1].y0, ostopoak[1].x1, ostopoak[1].y1, ostopoak[1].kolorea);

	//berdea
	JOKOA_laukiBatMargotu(ostopoak[2].x0, ostopoak[2].y0, ostopoak[2].x1, ostopoak[2].y1, ostopoak[2].kolorea);

//diamanteak
	//gorria
	JOKOA_diamanteBatMargotu(590, 240, DIAMANTE_GORRIA);
	//urdina
	JOKOA_diamanteBatMargotu(300, 430, DIAMANTE_URDINA);


	//ateak
	//urdina
	JOKOA_ateBatMargotu(20, 89, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(575, 449, GORRIA2);

	//plataforma mugikorra
	//botoia
	JOKOA_laukiBatMargotu(ostopoak[3].x0, ostopoak[3].y0, ostopoak[3].x1, ostopoak[3].y1, ostopoak[3].kolorea);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(ostopoak[4].x0, ostopoak[4].y0, ostopoak[4].x1, ostopoak[4].y1, ostopoak[4].kolorea);
}
