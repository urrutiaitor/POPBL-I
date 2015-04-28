#include "orokorrak.h"
#include "sarrera.h"


#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "text.h"

#define AUKERAKOPURUA 5
#define PANTAILAKOPURUA 7

void SARRERA_jokoarenAukerak(int x, int y, int zabalera, int altuera);
void SARRERA_pantailenAukerak(int x, int y, int zabalera, int altuera, int pantailaKopurua);
int SARRERA_pantailakAukeratu(int x, int y, int zabalera, int altuera);
void SARRERA_kredituak();

void SARRERA_jokoarenAukerak(int x, int y, int zabalera, int altuera){
	//aldagaiak
	int i = 0, t = 0;

	//programa
	
	borraCopiaPantalla();
	for (i = y; i < y + altuera; i++){
		for (t = x; t < x + zabalera; t++){
			plot(t, i, GRIS5);
		}
	}
	escribirTexto(225, 50, TITULOA);
	escribirTexto(150, 150, JOKOA);
	escribirTexto(150, 200, AZALPENA);
	escribirTexto(150, 250, RANKING);
	escribirTexto(150, 300, KREDITUAK);
	escribirTexto(150, 350, EXIT);
	actualizaPantalla();
}

void SARRERA_pantailenAukerak(int x, int y, int zabalera, int altuera, int pantailaKopurua){
	//aldagaiak
	int i = 0, t = 0;

	//programa

	borraCopiaPantalla();
	for (i = y; i < y + altuera; i++){
		for (t = x; t < x + zabalera; t++){
			plot(t, i, HORIA);
		}
	}
	if (pantailaKopurua == 1){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, EXIT);
	}
	if (pantailaKopurua == 2){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, AUKERA1);
		escribirTexto(150, 250, EXIT);
	}
	if (pantailaKopurua == 3){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, AUKERA1);
		escribirTexto(150, 250, AUKERA2);
		escribirTexto(150, 300, EXIT);
	}
	if (pantailaKopurua == 4){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, AUKERA1);
		escribirTexto(150, 250, AUKERA2);
		escribirTexto(150, 300, AUKERA3);
		escribirTexto(150, 350, EXIT);
	}
	if (pantailaKopurua == 5){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, AUKERA1);
		escribirTexto(150, 250, AUKERA2);
		escribirTexto(150, 300, AUKERA3);
		escribirTexto(150, 350, AUKERA4);
		escribirTexto(150, 400, EXIT);
	}
	if (pantailaKopurua == 6){
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 150, AUKERA0);
		escribirTexto(150, 200, AUKERA1);
		escribirTexto(150, 250, AUKERA2);
		escribirTexto(150, 300, AUKERA3);
		escribirTexto(150, 350, AUKERA4);
		escribirTexto(150, 400, AUKERA5);
		escribirTexto(150, 450, EXIT);
	}
	if (pantailaKopurua == 7){

	}
	actualizaPantalla();
}

int SARRERA_aukerakAukeratu(){
	int bukatu = 0;
	int tekla = 0;
	int posizioa = 1;
	
	do{

		tekla = ebentoaEntzun();
		if (tekla == TECLA_UP){
			if (posizioa > 1){
				posizioa = posizioa - 1;
			}
		}
		if (tekla == TECLA_DOWN){
			if (posizioa <AUKERAKOPURUA){
				posizioa = posizioa + 1;
			}
		}
		SARRERA_jokoarenAukerak(130,90+50*posizioa,200,30);

		if (tekla == TECLA_RETURN){
			bukatu = 1;
		}
		
	}while(bukatu==0);

	//return
	return posizioa;

}

int SARRERA_pantailakAukeratu(){
	int bukatu = 0;
	int tekla = 0;
	int posizioa = 1;
	int pantailaKopurua = 6;//aldatu egin behar da
	int i = 0;
	/* pantaila bakarra agertzeko
	for (i = 0; i < PANTAILAKOPURUA; i++){
		if (jokalariak[0].pantailaEgoerak[i] == AMAITUTA){
			pantailaKopurua++;
		}
	}
	*/

	do{

		tekla = ebentoaEntzun();
		if (tekla == TECLA_UP){
			if (posizioa > 1){
				posizioa = posizioa - 1;
			}
		}
		if (tekla == TECLA_DOWN){
			if (posizioa <PANTAILAKOPURUA){
				posizioa = posizioa + 1;
			}
		}
		SARRERA_pantailenAukerak(130, 90 + 50 * posizioa, 310, 30,pantailaKopurua);

		if (tekla == TECLA_RETURN){
			bukatu = 1;
		}

	} while (bukatu == 0);

	//return
	return posizioa;
}

void SARRERA_kredituak(){
	//aldagaiak
	int tekla = 0;

	//programa
	do{
		tekla = ebentoaEntzun();
		borraCopiaPantalla();
		escribirTexto(225, 50, TITULOA);
		escribirTexto(150, 200, IZENA1);
		escribirTexto(150, 250, IZENA2);
		escribirTexto(150, 300, IZENA3);
		escribirTexto(150, 350, IZENA4);
		actualizaPantalla();
	} while (tekla != TECLA_RETURN);
}