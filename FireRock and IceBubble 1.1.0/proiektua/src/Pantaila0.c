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
int PANTAILA0_pantailakoObjetuakKonprobatu(POSIZIOA bolarenPosizioa);

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
	JOKOA_laukiBatMargotu(0, 0, 639, 9, ZURIA);

	//beheko lerroa
	JOKOA_laukiBatMargotu(0, 469, 639, 479, ZURIA);
	

	//ezkerreko lerroa
	JOKOA_laukiBatMargotu(0, 0, 9, 479, ZURIA);
	

	//eskumako lerroa
	JOKOA_laukiBatMargotu(629, 0, 639, 479, ZURIA);
	
	

	//1.eskaloia
	JOKOA_laukiBatMargotu(149, 429, 349, 469, ZURIA);


	//2.eskaloia
	JOKOA_laukiBatMargotu(199, 389, 299, 429, ZURIA);
	

	//3.eskaloia
	JOKOA_laukiBatMargotu(399, 369, 499, 399, ZURIA);
	
}

int PANTAILA0_pantailakoObjetuakKonprobatu(int x0,int y0){
	//aldagaiak
	int x = 0, y = 0;
	int objetua = BELTZA;

	//programa

	//goiko lerroa
	if ((x0 >= 0) && (x0 <= 639) && (y0 >= 0) && (y0 <= 9)){
		objetua = ZURIA;
	}

	//beheko lerroa
	if ((x0 >= 0) && (x0 <= 639) && (y0 >= 469) && (y0 <= 479)){
		objetua = ZURIA;
	}
	
	//ezkerreko lerroa
	if ((x0 >= 0) && (x0 <= 9) && (y0 >= 0) && (y0 <= 479)){
		objetua = ZURIA;
	}

	//eskumako lerroa
	if ((x0 >= 629) && (x0 <= 639) && (y0 >= 0) && (y0 <= 479)){
		objetua = ZURIA;
	}

	//1.eskaloia
	if ((x0 >= 149) && (x0 <= 349) && (y0 >= 429) && (y0 <= 469)){
		objetua = ZURIA;
	}
	
	//2.eskaloia
	if ((x0 >= 199) && (x0 <= 299) && (y0 >= 389) && (y0 <= 429)){
		objetua = ZURIA;
	}

	//3.eskaloia
	if ((x0 >= 399) && (x0 <= 499) && (y0 >= 369) && (y0 <= 399)){
		objetua = ZURIA;
	}


	//return
	return objetua;
}