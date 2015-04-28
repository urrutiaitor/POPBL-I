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
	int batura = 0;
	int irten = 1;

	int talkaGorria = 0;
	int talkaUrdina = 0;

	C controls = { FALSE };

	TALKAPOSIZIOA bolaGorriaTalkaPuntuak[112];
	TALKAPOSIZIOA bolaUrdinaTalkaPuntuak[112];

	for (ilara = -ERRADIOBOLA; ilara <= ERRADIOBOLA; ilara++){
		for (zutabea = -ERRADIOBOLA; zutabea <= ERRADIOBOLA; zutabea++){
			if (((ilara*ilara) + (zutabea*zutabea) >= (ERRADIOBOLA*ERRADIOBOLA) - 20) && ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA) + 20)){
				bolaGorriaTalkaPuntuak[i + 1].x = zutabea;
				bolaGorriaTalkaPuntuak[i].y = ilara;
				bolaUrdinaTalkaPuntuak[i].x = zutabea;
				bolaUrdinaTalkaPuntuak[i].y = ilara;
				i++;
			}
		}
	}

	//programa

	posizioGorria.inertziaY = 0;
	posizioGorria.inertziaX = 0;
	posizioUrdina.inertziaY = 0;
	posizioUrdina.inertziaX = 0;

	do{
		controls = actualizaControles(controls);

		for (i = 0; i < 112; i++){
			bolaGorriaTalkaPuntuak[i].talkaPuntua = ZURIA;
		}


		posizioGorria.inertziaX = 0;
		posizioUrdina.inertziaX = 0;
		talkaGorria = 0;
		talkaUrdina = 0;
		irten = 0;


		for (i = 0; i < 112; i++){
			if (bolaGorriaTalkaPuntuak[i].y < 0){
				bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y + 1);
			}
			if (bolaGorriaTalkaPuntuak[i].y == 0){
				bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y);
			}
			if (bolaGorriaTalkaPuntuak[i].y > 0){
				bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y - 1);
			}


			if (bolaUrdinaTalkaPuntuak[i].y < 0){
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y + 1);
			}
			if (bolaUrdinaTalkaPuntuak[i].y == 0){
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y);
			}
			if (bolaUrdinaTalkaPuntuak[i].y > 0){
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y - 1);
			}
		}



		for (i = 0; i < 112; i++){
			if (bolaGorriaTalkaPuntuak[i].talkaPuntua == BELTZA){
				talkaGorria = 1;
			}
			if (bolaUrdinaTalkaPuntuak[i].talkaPuntua == BELTZA){
				talkaUrdina = 1;
			}
		}


		//BOLA GORRIA


		//grabitatea
		if (talkaGorria == 0){
			posizioGorria.inertziaY = posizioGorria.inertziaY + 1;
		}
		if (talkaGorria == 1){
			for (i = 0; i < 112; i++){
				if (bolaGorriaTalkaPuntuak[i].talkaPuntua == BELTZA){
					posizioGorria.inertziaX = (-posizioGorria.inertziaY * 5 * bolaGorriaTalkaPuntuak[i].x) / 200;
					posizioGorria.inertziaY = (posizioGorria.inertziaY * 5 * bolaGorriaTalkaPuntuak[i].y) / 200;
				}
			}
		}



		//saltoa

		if ((controls.keyboard.Uarrow == TRUE) && (posizioGorria.inertziaY == 0)){
			posizioGorria.inertziaY = -10;
		}

		//eskuma

		if ((controls.keyboard.Rarrow == TRUE) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != BELTZA)){
			posizioGorria.inertziaX = posizioGorria.inertziaX + 5;
		}

		//ezkerra

		if ((controls.keyboard.Larrow == TRUE) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != BELTZA)){
			posizioGorria.inertziaX = posizioGorria.inertziaX - 5;
		}

		//BOLA URDINA

		if (controls.keyboard.w == TRUE){

		}

		if (controls.keyboard.d == TRUE){
			posizioUrdina.x = posizioUrdina.x + 5;
		}

		if (controls.keyboard.a == TRUE){
			posizioUrdina.x = posizioUrdina.x - 5;
		}



		//posizioak aldatu banaka
		for (i = 0; ((i<200) && (irten == 0)); i++){
			posizioInizialaGorria = posizioGorria;
			posizioInizialaUrdina = posizioUrdina;

			if (posizioGorria.inertziaX != 0){
				if (i == (200 / posizioGorria.inertziaX)){
					if (posizioGorria.inertziaX>0){
						posizioGorria.x = posizioGorria.x + 1;
					}
					if (posizioGorria.inertziaX > 0){
						posizioGorria.x = posizioGorria.x - 1;
					}
				}
			}

			if (posizioGorria.inertziaY != 0){
				if (i == (200 / posizioGorria.inertziaY)){
					if (posizioGorria.inertziaY > 0){
						posizioGorria.y = posizioGorria.y + 1;
					}
					if (posizioGorria.inertziaY > 0){
						posizioGorria.y = posizioGorria.y - 1;
					}
				}
			}

			if (posizioUrdina.inertziaX != 0){
				if (i == (200 / posizioUrdina.inertziaX)){
					if (posizioUrdina.inertziaX > 0){
						posizioUrdina.x = posizioUrdina.x + 1;
					}
					if (posizioGorria.inertziaX > 0){
						posizioUrdina.x = posizioUrdina.x - 1;
					}
				}
			}

			if (posizioUrdina.inertziaY != 0){
				if (i == (200 / posizioUrdina.inertziaY)){
					if (posizioUrdina.inertziaY > 0){
						posizioUrdina.y = posizioUrdina.y + 1;
					}
					if (posizioGorria.inertziaY > 0){
						posizioUrdina.y = posizioUrdina.y - 1;
					}
				}
			}

			//konprobatu aldaketa bakoitza

			talkaGorria = 0;
			talkaUrdina = 0;


			for (i = 0; i < 112; i++){
				if (bolaGorriaTalkaPuntuak[i].y < 0){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y + 1);
				}
				if (bolaGorriaTalkaPuntuak[i].y == 0){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y);
				}
				if (bolaGorriaTalkaPuntuak[i].y > 0){
					bolaGorriaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + bolaGorriaTalkaPuntuak[i].x, posizioGorria.y + bolaGorriaTalkaPuntuak[i].y - 1);
				}

				if (bolaUrdinaTalkaPuntuak[i].y < 0){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y + 1);
				}
				if (bolaUrdinaTalkaPuntuak[i].y == 0){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y);
				}
				if (bolaUrdinaTalkaPuntuak[i].y > 0){
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = PANTAILA0_pantailakoObjetuakKonprobatu(posizioUrdina.x + bolaUrdinaTalkaPuntuak[i].x, posizioGorria.y + bolaUrdinaTalkaPuntuak[i].y - 1);
				}
			}

			for (i = 0; i < 112; i++){
				if (bolaGorriaTalkaPuntuak[i].talkaPuntua == BELTZA){
					talkaGorria = 1;
				}
				if (bolaUrdinaTalkaPuntuak[i].talkaPuntua == BELTZA){
					talkaUrdina = 1;
				}
			}

			//PANTAILAN PRINTATU

			borraCopiaPantalla();
			JOKOA_zelaiaMargotu(pantaila);
			JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
			JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
			actualizaPantalla();

			//segi edo irten
			if ((talkaGorria == 1) || (talkaUrdina == 1)){
				irten = 1;
			}
		}
	}while (amaituta == 0);
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