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


void PANTAILA4_pantailaMargotu();


int PANTAILA4_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	int amaituta;


	//programa
	posizioGorria.x = 590;
	posizioGorria.y = 450 - ERRADIOBOLA;

	posizioUrdina.x =150;
	posizioUrdina.y = 99 - ERRADIOBOLA;
	PANTAILA4_pantailaMargotu();
	 ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina, 5);


	//return
	return 1;

}

void PANTAILA4_pantailaMargotu(){
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
	JOKOA_laukiBatMargotu(0, 160, 250, 180, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(350, 180, 640, 210, BERDE_ILUNA);
	//erdikoa
	JOKOA_laukiBatMargotu(200, 300, 500, 330, BERDE_ILUNA);
	
//goiko plataforma
	//ezkerrekoa
	JOKOA_laukiBatMargotu(0, 100, 230, 130, BERDE_ILUNA);
	//eskuinekoa
	JOKOA_laukiBatMargotu(400, 100, 640, 130, BERDE_ILUNA);

//putzuak
	//gorria
	JOKOA_laukiBatMargotu(440, 100, 540, 110, GORRIA);

	//urdina
	JOKOA_laukiBatMargotu(230, 450, 430, 460, URDINA);

	//berdea
	JOKOA_laukiBatMargotu(300, 300, 400, 310, BERDEA);

//harria

	JOKOA_laukiBatMargotu(150, 400, 200, 450, HARRI_KOLOREA);

//ateak
	//urdina
	JOKOA_ateBatMargotu(574 , 99, URDINA2);

	//gorria
	JOKOA_ateBatMargotu(20, 99, GORRIA2);
//goiko pelotak eragiten duena
	//botoia
	JOKOA_laukiBatMargotu(225, 150, 245, 160, MOREA);
	
	//pelota
	JOKOA_pelotaTxikia(200, 94);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(270, 180, 350, 195, MOREA);

//beheko pelotak egiten duena
	//botoia
	JOKOA_laukiBatMargotu(495, 440, 515, 450, MOREA);

	//pelota
	JOKOA_pelotaTxikia(470, 294);

	//plataforma mugikorra
	JOKOA_laukiBatMargotu(120, 300, 200, 315, MOREA);

}