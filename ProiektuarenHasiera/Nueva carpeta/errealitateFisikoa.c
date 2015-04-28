#include "errealitateFisikoa.h"

#include "orokorrak.h"
#include "sarrera.h"

#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "text.h"

#define JUMPMAX 100
#define MUGIMENDUA 5
#define GKONSTANTEA 0.003

//koloreak
#define BELTZA 0
#define ZURIA 16777215
#define HORIA 65535
#define BERDEA 65280
#define GORRIA 255
#define URDINA 16711680
#define TURKESA 16776960
#define MAGENTA 16711935

void ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioGorria, POSIZIOA posizioUrdina, int pantaila){
	
	//aldagaiak
	int tekla = 0;
	int tGorria = 0;
	int tUrdina = 0;
	int x0 = 0, y0 = 0;

	int amaituta = 0;
	int saltoaGorria = 0;
	int saltoaUrdina = 0;
	int dGorria = 0, dUrdina = 0;

	int ilara = 0, zutabea = 0;
	#define ERRADIOBOLA 20
	int objetua = -1;

	//programa

	SDL_EnableKeyRepeat(500, 30);

	do{
		tekla = ebentoaEntzun();

		//BOLA GORRIAREN MUGIMENDUAK

		if (saltoaGorria == 0){
			if (tekla == TECLA_UP){
				saltoaGorria = 1;
				tGorria = 0;
			}
		}

		if (saltoaGorria == 1){
		
			if (tGorria < 50){
				posizioGorria.y = posizioGorria.y - 1;
			}
			x0 = posizioGorria.x;
			y0 = posizioGorria.y + ERRADIOBOLA;

			objetua = PANTAILA0_pantailakoObjetuakKonprobatu(x0,y0);
			dGorria = 0.5*GKONSTANTEA*tGorria*tGorria;
			if ((tGorria >= 50) && (objetua != 0)){
				posizioGorria.y = posizioGorria.y + 1; //1 dagoen lekuan dGorria jarri beharko litzateke
			}
			if (objetua == BELTZA){
				saltoaGorria = 0;
			}

			tGorria++;

		}

		if (tekla == TECLA_LEFT){
			posizioGorria.x = posizioGorria.x - MUGIMENDUA;
		}
		if (tekla == TECLA_RIGHT){
			posizioGorria.x = posizioGorria.x + MUGIMENDUA;
		}

		//BOLA URDINAREN MUGIMENDUAK

		if (saltoaUrdina == 0){
			if (tekla == TECLA_w){
				saltoaUrdina = 1;
			}
		}

		if (saltoaUrdina == 1){

			if (tUrdina < 50){
				posizioUrdina.y = posizioUrdina.y - 1;
			}
			if (tUrdina >= 50){
				posizioUrdina.y = posizioUrdina.y + 1;
			}
			tUrdina++;
			if (tUrdina == 100){ //hau da aldatu behar dena pelotak lurra ikutzean gelditzeko
				tUrdina = 0;
				saltoaUrdina = 0;
			}
		}

		if (tekla == TECLA_a){
			posizioUrdina.x = posizioUrdina.x - MUGIMENDUA;
		}
		if (tekla == TECLA_d){
			posizioUrdina.x = posizioUrdina.x + MUGIMENDUA;
		}

		borraCopiaPantalla();
		JOKOA_zelaiaMargotu(pantaila);
		JOKOA_zirkuluUrdinaBistaratu(posizioUrdina.x, posizioUrdina.y);
		JOKOA_zirkuluGorriaBistaratu(posizioGorria.x, posizioGorria.y);
		actualizaPantalla();
		

	} while (amaituta == 0);
}