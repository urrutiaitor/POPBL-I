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


void PANTAILA3_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	
	//aldagaiak
	int aukera = 2;

	//programa

	do{

		//harria
		ostopoak[0].kolorea = HARRI_KOLOREA;
		ostopoak[0].x0 = 150;
		ostopoak[0].y0 = 250;
		ostopoak[0].x1 = 200;
		ostopoak[0].y1 = 300;

		//botoia
		ostopoak[1].kolorea = MOREA_BOTOIA1;
		ostopoak[1].x0 = 590;
		ostopoak[1].y0 = 190;
		ostopoak[1].x1 = 610;
		ostopoak[1].y1 = 200;

		//plataforma mugikorra
		ostopoak[2].kolorea = MOREA_PLATAFORMA1;
		ostopoak[2].x0 = 275;
		ostopoak[2].y0 = 185;
		ostopoak[2].x1 = 355;
		ostopoak[2].y1 = 200;

		//diamanteak
		//gorria
		ostopoak[3].kolorea = DIAMANTE_GORRIA;
		ostopoak[3].x0 = 150;
		ostopoak[3].y0 = 80;
		ostopoak[3].x1 = 0;
		ostopoak[3].y1 = 0;
		
		//urdina
		ostopoak[4].kolorea = DIAMANTE_URDINA;
		ostopoak[4].x0 = 550;
		ostopoak[4].y0 = 60;
		ostopoak[4].x1 = 0;
		ostopoak[4].y1 = 0;

		posizioGorria.x = 590;
		posizioGorria.y = 79 - ERRADIOBOLA;

		posizioUrdina.x = 50;
		posizioUrdina.y = 99 - ERRADIOBOLA;

		do{

			aukera = ERREALITATE_FISIKOA_mugimendua(4);

		} while (aukera == 1);

	} while (aukera == 2);

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
	JOKOA_laukiBatMargotu(510, 340, 640, 370, BERDE_ILUNA);
	//luzea
	JOKOA_laukiBatMargotu(150, 200, 640, 230, BERDE_ILUNA);
	//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 100, 230, 130, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(400, 80, 640, 110, BERDE_ILUNA);

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu(100, 100, 150,110, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(90, 450, 190, 460, URDINA);

	//berdea
	JOKOA_laukiBatMargotu(440, 200, 490, 210, BERDEA);

	//harria
	
	JOKOA_laukiBatMargotu(ostopoak[0].x0, ostopoak[0].y0, ostopoak[0].x1, ostopoak[0].y1, ostopoak[0].kolorea);

	//diamanteak
	//gorria
	JOKOA_diamanteBatMargotu(ostopoak[3].x0, ostopoak[3].y0, ostopoak[3].kolorea);
	//urdina
	JOKOA_diamanteBatMargotu(ostopoak[4].x0, ostopoak[4].y0, ostopoak[4].kolorea);


	//ateak
	//urdina
	JOKOA_ateBatMargotu(575, 339, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(20, 449, GORRIA2);

	//botoia
	JOKOA_laukiBatMargotu(ostopoak[1].x0, ostopoak[1].y0, ostopoak[1].x1, ostopoak[1].y1, ostopoak[1].kolorea);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(ostopoak[2].x0, ostopoak[2].y0, ostopoak[2].x1, ostopoak[2].y1, ostopoak[2].kolorea);
}

void PANTAILA3_pantailaMargotu3D(){
	//aldagaiak
	int x = 0, y = 0;


	//programa


	//goiko lerroa
	JOKOA_laukiBatMargotu3D(0, 0, 640, 10, BLOKEA_FONDO);

	//beheko lerroa
	JOKOA_laukiBatMargotu3D(0, 450, 640, 480, BLOKEA_FONDO);


	//ezkerreko lerroa
	JOKOA_laukiBatMargotu3D(0, 0, 10, 480, BLOKEA_FONDO);


	//eskumako lerroa
	JOKOA_laukiBatMargotu3D(630, 0, 640, 480, BLOKEA_FONDO);


	//erdiko plataformaK 
	//ezkerrekoa
	JOKOA_laukiBatMargotu3D(0, 300, 250, 330, BLOKEA_FONDO);
	//eskuinekoa
	JOKOA_laukiBatMargotu3D(510, 340, 640, 370, BLOKEA_FONDO);
	//luzea
	JOKOA_laukiBatMargotu3D(150, 200, 640, 230, BLOKEA_FONDO);
	//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu3D(0, 100, 230, 130, BLOKEA_FONDO);
	//eskuinekoa
	JOKOA_laukiBatMargotu3D(400, 80, 640, 110, BLOKEA_FONDO);

	//putzuak
	//gorria
	JOKOA_laukiBatMargotu3D(100, 100, 150, 110, GORRIA_FONDO);

	//urdina
	JOKOA_laukiBatMargotu3D(90, 450, 190, 460, URDINA_FONDO);

	//berdea
	JOKOA_laukiBatMargotu3D(440, 200, 490, 210, BERDEA_FONDO);

	//harria

	JOKOA_laukiBatMargotu3D(ostopoak[0].x0, ostopoak[0].y0, ostopoak[0].x1, ostopoak[0].y1, GRIS2);

	//botoia
	JOKOA_laukiBatMargotu3D(ostopoak[1].x0, ostopoak[1].y0, ostopoak[1].x1, ostopoak[1].y1, ostopoak[1].kolorea);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu3D(ostopoak[2].x0, ostopoak[2].y0, ostopoak[2].x1, ostopoak[2].y1, ostopoak[2].kolorea);
}