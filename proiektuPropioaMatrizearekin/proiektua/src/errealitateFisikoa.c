#include "errealitateFisikoa.h"

#include "orokorrak.h"
#include "sarrera.h"

#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "text.h"
#include "mugimenduak.h"

#define JUMPMAX 100
#define MUGIMENDUA 5
#define GKONSTANTEA 0.003

void ERREALITATE_FISIKOA_mugimenduaEgin(POSIZIOA posizioGorria, POSIZIOA posizioUrdina, int pantaila);
int ERREALITATE_FISIKOA_mugimenduenDistantziak(int denbora);
int ERREALITATE_FISIKOA_erortzenDistantziak(int denbora);

void ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioGorria, POSIZIOA posizioUrdina, int pantaila){
	
	//aldagaiak
	int tekla = 0;
	int x0 = 0, y0 = 0;
	POSIZIOA posizioInizialaGorria;
	POSIZIOA posizioInizialaUrdina;
	int amaituta = 0;

	int goraGorria = 0, goraUrdina = 0;
	int tGoraGorria = 0, tGoraUrdina = 0;
	int dGoraGorria = 0, dGoraUrdina = 0;
	int amaitutaGoraGorria = 0, amaitutaGoraUrdina = 0;

	int ilara = 0, zutabea = 0;
	int objetua = -1;
	int talka = 0;
	int i = 0;
	int t = 0;
	int batura = 0;
	int irten = 1;
	int inertziaEremuTotala = 0;
	int kont = 0;
	int aux = 0;

	int talkaGorria = 0;
	int talkaUrdina = 0;

	C controls = { FALSE };

	TALKAPOSIZIOA bolaGorriaTalkaPuntuak[PUNTUKOPURUA];
	TALKAPOSIZIOA bolaUrdinaTalkaPuntuak[PUNTUKOPURUA];

	for (ilara = -ERRADIOBOLA; ilara <= ERRADIOBOLA; ilara++){
		for (zutabea = -ERRADIOBOLA; zutabea <= ERRADIOBOLA; zutabea++){
			if (((ilara*ilara) + (zutabea*zutabea) >= (ERRADIOBOLA*ERRADIOBOLA) - 20) && ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA) + 20)){
				bolaGorriaTalkaPuntuak[i].x = zutabea;
				bolaGorriaTalkaPuntuak[i].y = ilara;
				bolaUrdinaTalkaPuntuak[i].x = zutabea;
				bolaUrdinaTalkaPuntuak[i].y = ilara;
				i++;
			}
		}
	}

	//PANTAILAN PRINTATU

	borraCopiaPantalla();
	JOKOA_zelaiaMargotu(pantaila);
	JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
	JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
	actualizaPantalla();

	//programa

	posizioGorria.inertziaY = 0;
	posizioGorria.inertziaX = 0;
	posizioUrdina.inertziaY = 0;
	posizioUrdina.inertziaX = 0;

	do{
		controls = actualizaControles(controls);
		
		talkaGorria = 0;
		talkaUrdina = 0;
		posizioGorria.inertziaX = 0;
		posizioUrdina.inertziaX = 0;
		irten = 0;

		for (i = 0; i < PUNTUKOPURUA; i++){
			if (bolaGorriaTalkaPuntuak[i].y == -ERRADIOBOLA){
				bolaGorriaTalkaPuntuak[i].talkaPuntua =objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y - 1];
			}
			if (bolaGorriaTalkaPuntuak[i].y < 0){
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x - 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y - 1];
				}
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x + 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y - 1];
				}
			}
			if (bolaGorriaTalkaPuntuak[i].y == 0){
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x - 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y];
				}
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x + 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y];
				}
			}
			if (bolaGorriaTalkaPuntuak[i].y > 0){
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x - 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y + 1];
				}
				if ((bolaGorriaTalkaPuntuak[i].x < 0)){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x + 1, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y + 1];
				}
			}
			if (bolaGorriaTalkaPuntuak[i].y == ERRADIOBOLA){
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y + 1];
			}



			if (bolaUrdinaTalkaPuntuak[i].y == -ERRADIOBOLA){
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y - 1];
			}
			if (bolaUrdinaTalkaPuntuak[i].y < 0){
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x - 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y - 1];
				}
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x + 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y - 1];
				}
			}
			if (bolaUrdinaTalkaPuntuak[i].y == 0){
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x - 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y];
				}
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x + 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y];
				}
			}
			if (bolaUrdinaTalkaPuntuak[i].y > 0){
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x - 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y + 1];
				}
				if ((bolaUrdinaTalkaPuntuak[i].x < 0)){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x + 1, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y + 1];
				}
			}
			if (bolaUrdinaTalkaPuntuak[i].y == ERRADIOBOLA){
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y + 1];
			}
		}



		for (i = 0; i < PUNTUKOPURUA; i++){
			if (bolaGorriaTalkaPuntuak[i].talkaPuntua == ZURIA){
				talkaGorria = 1;
			}
			if (bolaUrdinaTalkaPuntuak[i].talkaPuntua == ZURIA){
				talkaUrdina = 1;
			}
		}


		//BOLA GORRIA

		//grabitatea
		if (objetuak[posizioGorria.x][posizioGorria.y+ERRADIOBOLA+1]==BELTZA){
			posizioGorria.inertziaY = posizioGorria.inertziaY + 2;
		}
		
		//saltoa

		if ((controls.keyboard.Uarrow == TRUE) && (posizioGorria.inertziaY == 0) && (objetuak[posizioGorria.x][posizioGorria.y+ERRADIOBOLA+1] == ZURIA)){
			posizioGorria.inertziaY = -15;
		}


		//BOLA URDINA

		if (controls.keyboard.w == TRUE){

		}

		if (controls.keyboard.d == TRUE){
			posizioUrdina.x = posizioUrdina.x + 15;
		}

		if (controls.keyboard.a == TRUE){
			posizioUrdina.x = posizioUrdina.x - 15;
		}

		
		//posizioak aldatu banaka
		if (posizioGorria.inertziaY != 0){
			posizioGorria.inertziaEremuaY = MUGIMENDUZATIKETA / posizioGorria.inertziaY;
		}
		if (posizioUrdina.inertziaY != 0){
			posizioUrdina.inertziaEremuaY = MUGIMENDUZATIKETA / posizioUrdina.inertziaY;
		}

		kont = 0;
		for (kont = 0; ((irten == 0) && (kont < MUGIMENDUZATIKETA)); kont++){
			posizioInizialaGorria = posizioGorria;
			posizioInizialaUrdina = posizioUrdina;

			if (posizioGorria.inertziaEremuaY != 0){
				if (kont%posizioGorria.inertziaEremuaY == 0){
					if (posizioGorria.inertziaY<0){
						posizioGorria.y = posizioGorria.y - 1;
					}
					if (posizioGorria.inertziaY>0){
						posizioGorria.y = posizioGorria.y + 1;
					}
				}
			}
			if (posizioUrdina.inertziaEremuaY != 0){
				if (kont%posizioUrdina.inertziaEremuaY == 0){
					if (posizioUrdina.inertziaY<0){
						posizioUrdina.y = posizioUrdina.y - 1;
					}
					if (posizioUrdina.inertziaY>0){
						posizioUrdina.y = posizioUrdina.y + 1;
					}
				}
			}
			//eskuma

			if ((controls.keyboard.Rarrow == TRUE) && (objetuak[posizioGorria.x + ERRADIOBOLA + 1][posizioGorria.y] != ZURIA)){
				posizioGorria.x = posizioGorria.x + 1;
			}

			//ezkerra

			if ((controls.keyboard.Larrow == TRUE) && (objetuak[posizioGorria.x - ERRADIOBOLA - 1][posizioGorria.y] != ZURIA)){
				posizioGorria.x = posizioGorria.x - 1;
			}


			for (i = 0; i < PUNTUKOPURUA; i++){
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + bolaGorriaTalkaPuntuak[i].x][posizioGorria.y + bolaGorriaTalkaPuntuak[i].y];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x][posizioUrdina.y + bolaUrdinaTalkaPuntuak[i].y];
			}


			for (i = 0; i < PUNTUKOPURUA; i++){
				if (bolaGorriaTalkaPuntuak[i].talkaPuntua == ZURIA){
					talkaGorria = 1;
				}
				if (bolaUrdinaTalkaPuntuak[i].talkaPuntua == ZURIA){
					talkaUrdina = 1;
				}
			}

			//segi edo irten
			if ((talkaGorria == 1) || (talkaUrdina == 1)){
				irten = 1;
				posizioGorria = posizioInizialaGorria;
				posizioUrdina = posizioInizialaUrdina;
			}

			//PANTAILAN PRINTATU

			borraCopiaPantalla();
			JOKOA_zelaiaMargotu(pantaila);
			JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
			JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
			actualizaPantalla();

		}

		

		//PANTAILAN PRINTATU

		borraCopiaPantalla();
		JOKOA_zelaiaMargotu(pantaila);
		JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
		JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
		actualizaPantalla();
	} while (amaituta == 0);
}

void ERREALITATE_FISIKOA_mugimenduaEgin(POSIZIOA posizioGorria, POSIZIOA posizioUrdina, int pantaila){

}

int ERREALITATE_FISIKOA_mugimenduenDistantziak(int denbora){
	//aldagaiak
	int distantzia = 0;

	//programa
	distantzia = 0.15*denbora*denbora + 8 * denbora;
	distantzia = 1;
	
	
	//return
	return distantzia;
}

int ERREALITATE_FISIKOA_erortzenDistantziak(int denbora){
	//aldagaiak
	int distantzia = 0;

	//programa

	distantzia = 0.5*GKONSTANTEA*denbora*denbora;

	//return
	return distantzia;
}