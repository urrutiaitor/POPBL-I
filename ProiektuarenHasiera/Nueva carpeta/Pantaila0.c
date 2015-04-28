//#include "orokorrak.h"
#include "Pantaila0.h"
//#include "jokoa.h"

//LIBRERIA GARFIKOA
#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
//LIBRERIA MATEMATIKOA
#include "math.h"

#define ERRADIOBOLA 20

//koloreak
#define BELTZA 0
#define ZURIA 16777215
#define HORIA 65535
#define BERDEA 65280
#define GORRIA 255
#define URDINA 16711680
#define TURKESA 16776960
#define MAGENTA 16711935


#define ERRADIOBOLA 20

void PANTAILA0_pantailaMargotu();
int PANTAILA0_pantailakoObjetuakKonprobatu(int x0, int y0);

int PANTAILA0_nagusia(){ //hau egin behar da bolaren mugimenduak eta pantaila eta ... lotzeko, nagusia.c -tik dator ona
	//aldagaiak
	POSIZIOA posizioGorria;
	POSIZIOA posizioUrdina;

	//programa
	posizioGorria.x = 50;
	posizioGorria.y = 470 - ERRADIOBOLA;

	posizioUrdina.x = 50 + 10 + ERRADIOBOLA + ERRADIOBOLA;
	posizioUrdina.y = 470 - ERRADIOBOLA;

	ERREALITATE_FISIKOA_mugimendua(posizioGorria, posizioUrdina, 1);

	//return
	return 1;

}

void PANTAILA0_pantailaMargotu(){
	//aldagaiak
	int x = 0, y = 0;

	//programa
	JOKOA_pantailaZuriz();

	//goiko lerroa
	for (y = 0; y < 10; y++){
		for (x = 0; x < 640; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//beheko lerroa
	for (y = 470; y <480; y++){
		for (x = 0; x < 640; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//ezkerreko lerroa
	for (y = 0; y < 480; y++){
		for (x = 0; x < 10; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//eskumako lerroa
	for (y = 0; y < 480; y++){
		for (x = 630; x < 640; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//1.eskaloia
	for (y = 430; y < 470; y++){
		for (x = 150; x < 350; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//2.eskaloia
	for (y = 390; y < 430; y++){
		for (x = 200; x < 300; x++){
			plot(x, y, BELTZA);
			
		}
	}

	//3.eskaloia
	for (y = 370; y < 400; y++){
		for (x = 400; x < 500; x++){
			plot(x, y, BELTZA);
			
		}
	}
}

int PANTAILA0_pantailakoObjetuakKonprobatu(int x0, int y0){
	//aldagaiak
	int x = 0, y = 0;
	int objetuak[640][480];
	int objetua = 0;

	//programa
	for (y = 0; y < 480; y++){
		for (x = 0; x < 640; x++){
			objetuak[x][y] = 16777215;

		}
	}

	//goiko lerroa
	for (y = 0; y < 10; y++){
		for (x = 0; x < 640; x++){
			objetuak[x][y] = 0;

		}
	}

	//beheko lerroa
	for (y = 470; y <480; y++){
		for (x = 0; x < 640; x++){
			objetuak[x][y] = 0;

		}
	}

	//ezkerreko lerroa
	for (y = 0; y < 480; y++){
		for (x = 0; x < 10; x++){
			objetuak[x][y] = 0;

		}
	}

	//eskumako lerroa
	for (y = 0; y < 480; y++){
		for (x = 630; x < 640; x++){
			objetuak[x][y] = 0;

		}
	}

	//1.eskaloia
	for (y = 430; y < 470; y++){
		for (x = 150; x < 350; x++){
			objetuak[x][y] = 0;

		}
	}

	//2.eskaloia
	for (y = 390; y < 430; y++){
		for (x = 200; x < 300; x++){
			objetuak[x][y] = 0;

		}
	}

	//3.eskaloia
	for (y = 370; y < 400; y++){
		for (x = 400; x < 500; x++){
			objetuak[x][y] = 0;

		}
	}
	objetua = objetuak[x0][y0];

	//return
	return objetua;
}