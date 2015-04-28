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

TALKAPOSIZIOA ERREALITATE_FISIKOA_talkakKonprobatu(POSIZIOA posizio);


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
	int ondo = 0;

	int kontGrabitateaGorria = 0;
	int kontGrabitateaUrdina = 0;

	int talkaGorria = 0;
	int talkaUrdina = 0;

	C controls = { FALSE };

	TALKAPOSIZIOA bolaGorriaTalkaPuntuak[80];
	TALKAPOSIZIOA bolaUrdinaTalkaPuntuak[80];
	TALKAPOSIZIOA bolaGorriaTalkaPuntua;
	TALKAPOSIZIOA bolaUrdinaTalkaPuntua;

	

	//programa

	jokalariak[0].pantailaEgoerak[pantaila] = JOLASTEN;

	posizioGorria.inertziaY = 0;
	posizioGorria.inertziaX = 0;
	posizioUrdina.inertziaY = 0;
	posizioUrdina.inertziaX = 0;

	do{
		controls = actualizaControles(controls);

		for (i = 0; i < 12; i++){
			bolaGorriaTalkaPuntuak[i].talkaPuntua = BELTZA;
		}
		for (i = 0; i < 12; i++){
			bolaUrdinaTalkaPuntuak[i].talkaPuntua = BELTZA;
		}

		posizioGorria.inertziaX = 0;
		posizioUrdina.inertziaX = 0;

		//talka puntuak aurkitu
		for (i = 0; i < 12; i++){

			switch (i){
			case 0:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x][posizioGorria.y + 20 + 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x][posizioUrdina.y + 20 + 1];
				break;
			case 1:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 12 - 1][posizioGorria.y + 12 + 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 12 - 1][posizioUrdina.y + 12 + 1];
				break;
			case 2:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 12 + 1][posizioGorria.y + 12 + 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 12 + 1][posizioUrdina.y + 12 + 1];
				break;
			case 3:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 16 - 1][posizioGorria.y + 12 + 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 16 - 1][posizioUrdina.y + 12 + 1];
				break;
			case 4:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 16 - 1][posizioGorria.y + 12 + 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 16 - 1][posizioUrdina.y + 12 + 1];
				break;
			case 5:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 20 - 1][posizioGorria.y];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 20 - 1][posizioUrdina.y];
				break;
			case 6:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 20 - 1][posizioGorria.y];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 20 - 1][posizioUrdina.y];
				break;
			case 7:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 16 - 1][posizioGorria.y - 12 - 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 16 - 1][posizioUrdina.y - 12 - 1];
				break;
			case 8:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 16 + 1][posizioGorria.y - 12 - 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 16 + 1][posizioUrdina.y - 12 - 1];
				break;
			case 9:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 12 + 1][posizioGorria.y - 16 - 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 12 + 1][posizioUrdina.y - 16 - 1];
				break;
			case 10:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 12 + 1][posizioGorria.y - 16 - 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 12 + 1][posizioUrdina.y - 16 - 1];
				break;
			case 11:
				bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x][posizioGorria.y - 20 - 1];
				bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x][posizioUrdina.y - 20 - 1];
				break;
			}
		}
		
		//talkak berdearekin
		if (bolaGorriaTalkaPuntuak[0].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaY = -(2*(posizioGorria.inertziaY/3));
		}
		if (bolaGorriaTalkaPuntuak[3].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if (bolaGorriaTalkaPuntuak[1].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if (bolaGorriaTalkaPuntuak[2].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if (bolaGorriaTalkaPuntuak[4].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}

		if (bolaGorriaTalkaPuntuak[11].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaY = -(2 * (posizioGorria.inertziaY / 3));
		}
		if (bolaGorriaTalkaPuntuak[8].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if (bolaGorriaTalkaPuntuak[10].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if (bolaGorriaTalkaPuntuak[9].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if (bolaGorriaTalkaPuntuak[7].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if (bolaGorriaTalkaPuntuak[5].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaX / 3);
		}
		if (bolaGorriaTalkaPuntuak[6].talkaPuntua == BERDE_ILUNA){
			posizioGorria.inertziaX = -(posizioGorria.inertziaX / 3);
		}


		if (bolaUrdinaTalkaPuntuak[0].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaY = -(2 * (posizioUrdina.inertziaY / 3));
		}
		if (bolaUrdinaTalkaPuntuak[3].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if (bolaUrdinaTalkaPuntuak[1].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if (bolaUrdinaTalkaPuntuak[2].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if (bolaUrdinaTalkaPuntuak[4].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}

		if (bolaUrdinaTalkaPuntuak[11].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaY = -(2 * (posizioUrdina.inertziaY / 3));
		}
		if (bolaUrdinaTalkaPuntuak[8].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if (bolaUrdinaTalkaPuntuak[10].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if (bolaUrdinaTalkaPuntuak[9].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if (bolaUrdinaTalkaPuntuak[7].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if (bolaUrdinaTalkaPuntuak[5].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaX / 3);
		}
		if (bolaUrdinaTalkaPuntuak[6].talkaPuntua == BERDE_ILUNA){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaX / 3);
		}		

		//BOLA GORRIA MUGIMENDUAK
		//grabitatea
		if (bolaGorriaTalkaPuntuak[0].talkaPuntua == BELTZA){
			kontGrabitateaGorria++;
			if (kontGrabitateaGorria == 6){
				posizioGorria.inertziaY = posizioGorria.inertziaY + 1;
				kontGrabitateaGorria = 0;
			}
			
		}

		//saltoa

		if ((controls.keyboard.Uarrow == TRUE) && (posizioGorria.inertziaY == 0)){
			posizioGorria.inertziaY = -6;
		}

		//eskuma

		if ((controls.keyboard.Rarrow == TRUE) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != BERDE_ILUNA)){
			posizioGorria.inertziaX = posizioGorria.inertziaX + 2;
		}

		//ezkerra

		if ((controls.keyboard.Larrow == TRUE) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != BERDE_ILUNA)){
			posizioGorria.inertziaX = posizioGorria.inertziaX - 2;
		}

		posizioGorria.y = posizioGorria.y + posizioGorria.inertziaY;
		posizioGorria.x = posizioGorria.x + posizioGorria.inertziaX;
		
		//BOLA URDINA
		//grabitatea
		if (bolaUrdinaTalkaPuntuak[0].talkaPuntua == BELTZA){
			kontGrabitateaUrdina++;
			if (kontGrabitateaUrdina == 6){
				posizioUrdina.inertziaY = posizioUrdina.inertziaY + 1;
				kontGrabitateaUrdina = 0;
			}

		}

		//saltoa

		if ((controls.keyboard.w == TRUE) && (posizioUrdina.inertziaY == 0)){
			posizioUrdina.inertziaY = -6;
		}

		//eskuma

		if ((controls.keyboard.d == TRUE) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != BERDE_ILUNA)){
			posizioUrdina.inertziaX = posizioUrdina.inertziaX + 2;
		}

		//ezkerra

		if ((controls.keyboard.a == TRUE) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != BERDE_ILUNA)){
			posizioUrdina.inertziaX = posizioUrdina.inertziaX - 2;
		}

		posizioUrdina.y = posizioUrdina.y + posizioUrdina.inertziaY;
		posizioUrdina.x = posizioUrdina.x + posizioUrdina.inertziaX;

		//MUGIMENDU OSTEKO TALKAK KONPROBATU
		talka = 1;
		while (talka == 1){
			talka = 0;
			for (i = 0; i < 12; i++){
				switch (i){
				case 0:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x][posizioGorria.y + 20];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x][posizioUrdina.y + 20];
					break;
				case 1:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 12][posizioGorria.y + 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 12][posizioUrdina.y + 12];
					if (bolaGorriaTalkaPuntuak[i].talkaPuntua == BERDE_ILUNA){
						printf("");
					}
					break;
				case 2:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 12][posizioGorria.y + 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 12][posizioUrdina.y + 12];
					break;
				case 3:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 16][posizioGorria.y + 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 16][posizioUrdina.y + 12];
					break;
				case 4:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 16][posizioGorria.y + 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 16][posizioUrdina.y + 12];
					break;
				case 5:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 20][posizioGorria.y];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 20][posizioUrdina.y];
					break;
				case 6:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 20][posizioGorria.y];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 20][posizioUrdina.y];
					break;
				case 7:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 16][posizioGorria.y - 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 16][posizioUrdina.y - 12];
					break;
				case 8:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 16][posizioGorria.y - 12];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 16][posizioUrdina.y - 12];
					break;
				case 9:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x - 12][posizioGorria.y - 16];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x - 12][posizioUrdina.y - 16];
					break;
				case 10:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x + 12][posizioGorria.y - 16];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x + 12][posizioUrdina.y - 16];
					break;
				case 11:
					bolaGorriaTalkaPuntuak[i].talkaPuntua = objetuak[posizioGorria.x][posizioGorria.y - 20];
					bolaUrdinaTalkaPuntuak[i].talkaPuntua = objetuak[posizioUrdina.x][posizioUrdina.y - 20];
					break;
				}
				if (bolaGorriaTalkaPuntuak[i].talkaPuntua == BERDE_ILUNA){
					talka = 1;
					switch (i){
					case 0:
						posizioGorria.y = posizioGorria.y - 1;
						break;
					case 1:
						posizioGorria.x = posizioGorria.x + 1;
						posizioGorria.y = posizioGorria.y - 1;
					case 2:
						posizioGorria.x = posizioGorria.x - 1;
						posizioGorria.y = posizioGorria.y - 1;
						break;
					case 3:
						posizioGorria.x = posizioGorria.x + 1;
						posizioGorria.y = posizioGorria.y - 1;
						break;
					case 4:
						posizioGorria.x = posizioGorria.x - 1;
						posizioGorria.y = posizioGorria.y - 1;
						break;
					case 5:
						posizioGorria.x = posizioGorria.x + 1;
						break;
					case 6:
						posizioGorria.x = posizioGorria.x - 1;
						break;
					case 7:
						posizioGorria.x = posizioGorria.x + 1;
						posizioGorria.y = posizioGorria.y + 1;
						break;
					case 8:
						posizioGorria.x = posizioGorria.x - 1;
						posizioGorria.y = posizioGorria.y + 1;
						break;
					case 9:
						posizioGorria.x = posizioGorria.x + 1;
						posizioGorria.y = posizioGorria.y + 1;
						break;
					case 10:
						posizioGorria.x = posizioGorria.x - 1;
						posizioGorria.y = posizioGorria.y + 1;
						break;
					case 11:
						posizioGorria.y = posizioGorria.y + 1;
						break;
					}
				}
				if (bolaUrdinaTalkaPuntuak[i].talkaPuntua == BERDE_ILUNA){
					talka = 1;
					switch (i){
					case 0:
						posizioUrdina.y = posizioUrdina.y - 1;
						break;
					case 1:
						posizioUrdina.x = posizioUrdina.x + 1;
						posizioUrdina.y = posizioUrdina.y - 1;
					case 2:
						posizioUrdina.x = posizioUrdina.x - 1;
						posizioUrdina.y = posizioUrdina.y - 1;
						break;
					case 3:
						posizioUrdina.x = posizioUrdina.x + 1;
						posizioUrdina.y = posizioUrdina.y - 1;
						break;
					case 4:
						posizioUrdina.x = posizioUrdina.x - 1;
						posizioUrdina.y = posizioUrdina.y - 1;
						break;
					case 5:
						posizioUrdina.x = posizioUrdina.x + 1;
						break;
					case 6:
						posizioUrdina.x = posizioUrdina.x - 1;
						break;
					case 7:
						posizioUrdina.x = posizioUrdina.x + 1;
						posizioUrdina.y = posizioUrdina.y + 1;
						break;
					case 8:
						posizioUrdina.x = posizioUrdina.x - 1;
						posizioUrdina.y = posizioUrdina.y + 1;
						break;
					case 9:
						posizioUrdina.x = posizioUrdina.x + 1;
						posizioUrdina.y = posizioUrdina.y + 1;
						break;
					case 10:
						posizioUrdina.x = posizioUrdina.x - 1;
						posizioUrdina.y = posizioUrdina.y + 1;
						break;
					case 11:
						posizioUrdina.y = posizioUrdina.y + 1;
						break;
					}
				}
			}
		}

		//OSTOPOEN MUGIMENDUAK
		for (i = 0; i < OSTOPOKOPURUA; i++){
			if (ostopoak[i].kolorea == HARRI_KOLOREA){
				while (ondo == 0){
					ondo = 1;
					if ((ostopoak[i].x0<posizioGorria.x+ERRADIOBOLA) && (ostopoak[i].x0>posizioGorria.x) && (ostopoak[i].y1 + ERRADIOBOLA == posizioGorria.y)){
						ostopoak[i].x0 = ostopoak[i].x0 + 1;
						ostopoak[i].x1 = ostopoak[i].x1 + 1;
						ondo = 0;
					}
					if ((ostopoak[i].x1>posizioGorria.x-ERRADIOBOLA) && (ostopoak[i].x1<posizioGorria.x) && (ostopoak[i].y1 + ERRADIOBOLA == posizioGorria.y)){
						ostopoak[i].x0 = ostopoak[i].x0 - 1;
						ostopoak[i].x1 = ostopoak[i].x1 - 1;
						ondo = 0;
					}
					
				}
			}
		}

		_sleep(1);

		//PANTAILAN PRINTATU

		borraCopiaPantalla();
		JOKOA_zelaiaMargotu(pantaila);
		JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
		JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
		actualizaPantalla();

		//HELMUGAK KONPROBATU
		if ((objetuak[posizioGorria.x][posizioGorria.y] == GORRIA2) && (objetuak[posizioUrdina.x][posizioUrdina.y] == URDINA2)){
			jokalariak[0].pantailaEgoerak[pantaila] = AMAITUTA;
		}
		

		
	} while (jokalariak[0].pantailaEgoerak[pantaila] == JOLASTEN);
}