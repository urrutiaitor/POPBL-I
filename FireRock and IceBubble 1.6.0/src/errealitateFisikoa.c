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

int ERREALITATE_FISIKOA_pantailaGeratu();
void ERREALITATE_FISIKOA_pantailaGeratuPrintatu(int x, int y, int zabalera, int altuera);
int ERREALITATE_FISIKOA_pantailaBukaera();
void ERREALITATE_FISIKOA_pantailaBukaeraPrintatu(int x, int y, int zabalera, int altuera);
int ERREALITATE_FISIKOA_pantailaBukaeraHil();
void ERREALITATE_FISIKOA_pantailaBukaeraHilPrintatu(int x, int y, int zabalera, int altuera);


int ERREALITATE_FISIKOA_mugimendua(int pantaila){
	
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
	int t = 0;
	int jarraitu = 1;
	int emaitza = 0;

	int kontGrabitateaGorria = 0;
	int kontGrabitateaUrdina = 0;

	int kontLeb1 = 0;
	int kontLeb2 = 0;

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

	//PANTAILAN PRINTATU

	borraCopiaPantalla();
	JOKOA_zelaiaMargotu(pantaila);
	JOKOA_zirkuluaBistaratu(posizioUrdina.x, posizioUrdina.y, URDINA);
	JOKOA_zirkuluaBistaratu(posizioGorria.x, posizioGorria.y, GORRIA);
	actualizaPantalla();

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
		if ((bolaGorriaTalkaPuntuak[0].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[0].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[0].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[0].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[0].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaY = -(2*(posizioGorria.inertziaY/3));
		}
		if ((bolaGorriaTalkaPuntuak[3].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[3].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[3].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[3].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[3].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if ((bolaGorriaTalkaPuntuak[1].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[1].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[1].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[1].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[1].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if ((bolaGorriaTalkaPuntuak[2].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[2].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[2].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[2].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[2].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if ((bolaGorriaTalkaPuntuak[4].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[4].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[4].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[4].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[4].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}

		if ((bolaGorriaTalkaPuntuak[11].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[11].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[11].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[11].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[11].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaY = -(2 * (posizioGorria.inertziaY / 3));
		}
		if ((bolaGorriaTalkaPuntuak[8].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[8].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[8].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[8].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[8].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if ((bolaGorriaTalkaPuntuak[10].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[10].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[10].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[10].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[10].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = +(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if ((bolaGorriaTalkaPuntuak[9].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[9].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[9].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[9].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[9].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 4);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 2);
		}
		if ((bolaGorriaTalkaPuntuak[7].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[7].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[7].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[7].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[7].talkaPuntua != DIAMANTE_URDINA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaY / 2);
			posizioGorria.inertziaY = -(posizioGorria.inertziaY / 4);
		}
		if ((bolaGorriaTalkaPuntuak[5].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != DIAMANTE_URDINA) && (bolaGorriaTalkaPuntuak[5].talkaPuntua != HARRI_KOLOREA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaX / 3);
		}
		if ((bolaGorriaTalkaPuntuak[6].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != DIAMANTE_URDINA) && (bolaGorriaTalkaPuntuak[6].talkaPuntua != HARRI_KOLOREA)){
			posizioGorria.inertziaX = -(posizioGorria.inertziaX / 3);
		}


		if ((bolaUrdinaTalkaPuntuak[0].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[0].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[0].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[0].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[0].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaY = -(2 * (posizioUrdina.inertziaY / 3));
		}
		if ((bolaUrdinaTalkaPuntuak[3].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[3].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[3].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[3].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[3].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if ((bolaUrdinaTalkaPuntuak[1].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[1].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[1].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[1].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[1].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if ((bolaUrdinaTalkaPuntuak[2].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[2].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[2].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[2].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[2].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if ((bolaUrdinaTalkaPuntuak[4].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[4].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[4].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[4].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[4].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}

		if ((bolaUrdinaTalkaPuntuak[11].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[11].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[11].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[11].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[11].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaY = -(2 * (posizioUrdina.inertziaY / 3));
		}
		if ((bolaUrdinaTalkaPuntuak[8].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[8].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[8].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[8].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[8].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if ((bolaUrdinaTalkaPuntuak[10].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[10].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[10].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[10].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[10].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = +(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if ((bolaUrdinaTalkaPuntuak[9].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[9].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[9].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[9].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[9].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 4);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 2);
		}
		if ((bolaUrdinaTalkaPuntuak[7].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[7].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[7].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[7].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[7].talkaPuntua != DIAMANTE_URDINA)){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaY / 2);
			posizioUrdina.inertziaY = -(posizioUrdina.inertziaY / 4);
		}
		if ((bolaUrdinaTalkaPuntuak[5].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != DIAMANTE_URDINA) && (bolaUrdinaTalkaPuntuak[5].talkaPuntua != HARRI_KOLOREA)){
			posizioUrdina.inertziaX = -(posizioUrdina.inertziaX / 3);
		}
		if ((bolaUrdinaTalkaPuntuak[6].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != DIAMANTE_URDINA) && (bolaUrdinaTalkaPuntuak[6].talkaPuntua != HARRI_KOLOREA)){
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

		if ((controls.keyboard.Uarrow == TRUE) && (posizioGorria.inertziaY == 0) && ((bolaGorriaTalkaPuntuak[0].talkaPuntua == BERDE_ILUNA) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == MOREA_BOTOIA1) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == MOREA_PLATAFORMA1) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == MOREA_BOTOIA2) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == MOREA_PLATAFORMA2) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == HARRI_KOLOREA) || (bolaGorriaTalkaPuntuak[0].talkaPuntua == HARRI_BOROBILA))){
			posizioGorria.inertziaY = -5;
		}

		//eskuma

		if ((controls.keyboard.Rarrow == TRUE) && ((bolaGorriaTalkaPuntuak[6].talkaPuntua != BERDE_ILUNA) || (bolaGorriaTalkaPuntuak[6].talkaPuntua != MOREA_BOTOIA1) || (bolaGorriaTalkaPuntuak[6].talkaPuntua != MOREA_PLATAFORMA1) || (bolaGorriaTalkaPuntuak[6].talkaPuntua != MOREA_BOTOIA2) || (bolaGorriaTalkaPuntuak[6].talkaPuntua != MOREA_PLATAFORMA2) || (bolaGorriaTalkaPuntuak[6].talkaPuntua != HARRI_BOROBILA))){
			posizioGorria.inertziaX = posizioGorria.inertziaX + 3;
		}

		//ezkerra

		if ((controls.keyboard.Larrow == TRUE) && ((bolaGorriaTalkaPuntuak[5].talkaPuntua != BERDE_ILUNA) || (bolaGorriaTalkaPuntuak[5].talkaPuntua != MOREA_BOTOIA1) || (bolaGorriaTalkaPuntuak[5].talkaPuntua != MOREA_PLATAFORMA1) || (bolaGorriaTalkaPuntuak[5].talkaPuntua != MOREA_BOTOIA2) || (bolaGorriaTalkaPuntuak[5].talkaPuntua != MOREA_PLATAFORMA2) || (bolaGorriaTalkaPuntuak[5].talkaPuntua != HARRI_BOROBILA))){
			posizioGorria.inertziaX = posizioGorria.inertziaX - 3;
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

		if ((controls.keyboard.w == TRUE) && (posizioUrdina.inertziaY == 0) && ((bolaUrdinaTalkaPuntuak[0].talkaPuntua == BERDE_ILUNA) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == MOREA_BOTOIA1) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == MOREA_PLATAFORMA1) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == MOREA_BOTOIA2) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == MOREA_PLATAFORMA2) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == HARRI_KOLOREA) || (bolaUrdinaTalkaPuntuak[0].talkaPuntua == HARRI_BOROBILA))){
			posizioUrdina.inertziaY = -5;
		}

		//eskuma

		if ((controls.keyboard.d == TRUE) && ((bolaUrdinaTalkaPuntuak[6].talkaPuntua != BERDE_ILUNA) || (bolaUrdinaTalkaPuntuak[6].talkaPuntua != MOREA_BOTOIA1) || (bolaUrdinaTalkaPuntuak[6].talkaPuntua != MOREA_PLATAFORMA1) || (bolaUrdinaTalkaPuntuak[6].talkaPuntua != MOREA_BOTOIA2) || (bolaUrdinaTalkaPuntuak[6].talkaPuntua != MOREA_PLATAFORMA2) || (bolaUrdinaTalkaPuntuak[6].talkaPuntua != HARRI_BOROBILA))){
			posizioUrdina.inertziaX = posizioUrdina.inertziaX + 3;
		}

		//ezkerra

		if ((controls.keyboard.a == TRUE) && ((bolaUrdinaTalkaPuntuak[5].talkaPuntua != BERDE_ILUNA) || (bolaUrdinaTalkaPuntuak[5].talkaPuntua != MOREA_BOTOIA1) || (bolaUrdinaTalkaPuntuak[5].talkaPuntua != MOREA_PLATAFORMA1) || (bolaUrdinaTalkaPuntuak[5].talkaPuntua != MOREA_BOTOIA2) || (bolaUrdinaTalkaPuntuak[5].talkaPuntua != MOREA_PLATAFORMA2) || (bolaUrdinaTalkaPuntuak[5].talkaPuntua != HARRI_BOROBILA))){
			posizioUrdina.inertziaX = posizioUrdina.inertziaX - 3;
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
				if ((bolaGorriaTalkaPuntuak[i].talkaPuntua != BELTZA) && (bolaGorriaTalkaPuntuak[i].talkaPuntua != DIAMANTE_GORRIA) && (bolaGorriaTalkaPuntuak[i].talkaPuntua != GORRIA2) && (bolaGorriaTalkaPuntuak[i].talkaPuntua != DIAMANTE_URDINA) && (bolaGorriaTalkaPuntuak[i].talkaPuntua != URDINA2) && (bolaGorriaTalkaPuntuak[i].talkaPuntua != HARRI_KOLOREA)){
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
				if ((bolaUrdinaTalkaPuntuak[i].talkaPuntua != BELTZA) && (bolaUrdinaTalkaPuntuak[i].talkaPuntua != DIAMANTE_GORRIA) && (bolaUrdinaTalkaPuntuak[i].talkaPuntua != GORRIA2) && (bolaUrdinaTalkaPuntuak[i].talkaPuntua != DIAMANTE_URDINA) && (bolaUrdinaTalkaPuntuak[i].talkaPuntua != URDINA2) && (bolaUrdinaTalkaPuntuak[i].talkaPuntua != HARRI_KOLOREA)){
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
			
			
			ondo = 0;
			if (ostopoak[i].kolorea == HARRI_KOLOREA){
				while (ondo == 0){
					ondo = 1;
					jarraitu = 1;
					for (t = 0; t < 50; t++){
						if ((objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != DIAMANTE_GORRIA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != DIAMANTE_URDINA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != URDINA2) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != GORRIA2) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != BELTZA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != HARRI_KOLOREA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != GORRIA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != URDINA)){
							jarraitu = 0;
						}
					}
					if ((posizioGorria.y <= ostopoak[i].y1) && (posizioGorria.y >= ostopoak[i].y0) && ((ostopoak[i].x0 == posizioGorria.x + ERRADIOBOLA) || (ostopoak[i].x0 == posizioGorria.x + ERRADIOBOLA + 1) || (ostopoak[i].x0 == posizioGorria.x + ERRADIOBOLA + 2) || (ostopoak[i].x0 == posizioGorria.x + ERRADIOBOLA + 3)) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 + 1;
						ostopoak[i].x1 = ostopoak[i].x1 + 1;
						ondo = 0;
					}
					if ((posizioUrdina.y <= ostopoak[i].y1) && (posizioUrdina.y >= ostopoak[i].y0) && ((ostopoak[i].x0 == posizioUrdina.x + ERRADIOBOLA) || (ostopoak[i].x0 == posizioUrdina.x + ERRADIOBOLA + 1) || (ostopoak[i].x0 == posizioUrdina.x + ERRADIOBOLA + 2) || (ostopoak[i].x0 == posizioUrdina.x + ERRADIOBOLA + 3)) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 + 1;
						ostopoak[i].x1 = ostopoak[i].x1 + 1;
						ondo = 0;
					}

					jarraitu = 1;
					for (t = 0; t < 50; t++){
						if ((objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != DIAMANTE_GORRIA) && (objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != DIAMANTE_URDINA) && (objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != URDINA2) && (objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != GORRIA2) && (objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != HARRI_KOLOREA) && (objetuak[ostopoak[i].x0 - 1][ostopoak[i].y0 + t] != BELTZA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != GORRIA) && (objetuak[ostopoak[i].x1 + 1][ostopoak[i].y0 + t] != URDINA)){
							jarraitu = 0;
						}
					}
					if ((posizioGorria.y <= ostopoak[i].y1) && (posizioGorria.y >= ostopoak[i].y0) && ((ostopoak[i].x1 == posizioGorria.x - ERRADIOBOLA) || (ostopoak[i].x1 + 1 == posizioGorria.x - ERRADIOBOLA) || (ostopoak[i].x1 + 2 == posizioGorria.x - ERRADIOBOLA)) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 - 1;
						ostopoak[i].x1 = ostopoak[i].x1 - 1;
						ondo = 0;
					}
					if ((posizioUrdina.y <= ostopoak[i].y1) && (posizioUrdina.y >= ostopoak[i].y0) && ((ostopoak[i].x1 == posizioUrdina.x - ERRADIOBOLA) || (ostopoak[i].x1 + 1 == posizioUrdina.x - ERRADIOBOLA) || (ostopoak[i].x1 + 2 == posizioUrdina.x - ERRADIOBOLA)) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 - 1;
						ostopoak[i].x1 = ostopoak[i].x1 - 1;
						ondo = 0;
					}	
				}
				
				jarraitu = 1;
				for (t = 0; t < 50; t++){
					if ((objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == BERDE_ILUNA) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == HARRI_KOLOREA) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == HARRI_BOROBILA) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == MOREA_BOTOIA1) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == MOREA_PLATAFORMA1) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == MOREA_BOTOIA2) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y1 + 1] == MOREA_PLATAFORMA2)){
						jarraitu = 0;
					}
				}
				if (jarraitu==1){
					ostopoak[i].y0 = ostopoak[i].y0 + 1;
					ostopoak[i].y1 = ostopoak[i].y1 + 1;
				}
			}

			ondo = 0;
			if (ostopoak[i].kolorea == HARRI_BOROBILA){
				while (ondo == 0){
					ondo = 1;
					jarraitu = 1;

					if ((objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != DIAMANTE_GORRIA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != DIAMANTE_URDINA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != URDINA2) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != GORRIA2) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != BELTZA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != HARRI_KOLOREA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != GORRIA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != URDINA)){
						jarraitu = 0;
					}

					if ((posizioGorria.x+4 == ostopoak[i].x0) && (posizioGorria.y+3 == ostopoak[i].y0) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 + 1;
						ostopoak[i].x1 = ostopoak[i].x1 + 1;
						ondo = 0;
					}
					if ((posizioUrdina.x + 4 == ostopoak[i].x0) && (posizioUrdina.y + 3 == ostopoak[i].y0) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 + 1;
						ostopoak[i].x1 = ostopoak[i].x1 + 1;
						ondo = 0;
					}

					if ((objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != DIAMANTE_GORRIA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != DIAMANTE_URDINA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != URDINA2) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != GORRIA2) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != BELTZA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != HARRI_KOLOREA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != GORRIA) && (objetuak[ostopoak[i].x0 + 6][ostopoak[i].y0] != URDINA)){
						jarraitu = 0;
					}

					if ((posizioGorria.x - 4 == ostopoak[i].x0) && (posizioGorria.y + 3 == ostopoak[i].y0) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 - 1;
						ondo = 0;
					}
					if ((posizioUrdina.x - 4 == ostopoak[i].x0) && (posizioUrdina.y + 3 == ostopoak[i].y0) && (jarraitu == 1)){
						ostopoak[i].x0 = ostopoak[i].x0 - 1;
						ondo = 0;
					}
				}

				jarraitu = 1;
				
				if ((objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == BERDE_ILUNA) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == HARRI_KOLOREA) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == HARRI_BOROBILA) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == MOREA_BOTOIA1) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == MOREA_PLATAFORMA1) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == MOREA_BOTOIA2) || (objetuak[ostopoak[i].x0][ostopoak[i].y0 + 6] == MOREA_PLATAFORMA2)){
						jarraitu = 0;
					}
				
				if (jarraitu == 1){
					ostopoak[i].y0 = ostopoak[i].y0 + 1;
				}
			}
			
			ondo = 0;
			jarraitu = 0;
			if (ostopoak[i].kolorea == MOREA_BOTOIA1){
				for (t = 0; t < 20; t++){
					if ((objetuak[ostopoak[i].x0 + t][ostopoak[i].y0 - 1] == HARRI_BOROBILA) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y0 - 1] == HARRI_KOLOREA) || ((ostopoak[i].x0 + t == posizioGorria.x) && (ostopoak[i].y0 - 1 - ERRADIOBOLA == posizioGorria.y)) || ((ostopoak[i].x0 + t == posizioUrdina.x) && (ostopoak[i].y0 - 1 - ERRADIOBOLA == posizioUrdina.y))){
						jarraitu = 1;
					}
				}
				if (jarraitu == 1){
					//ostopoak[i].y0 = ostopoak[i].y1 - 5;
					if (kontLeb2 < 75){
						ostopoak[i + 1].y0--;
						ostopoak[i + 1].y1--;
						kontLeb1++;
					}
				}
				if (jarraitu == 0){
					//ostopoak[i].y0 = ostopoak[i].y1 - 10;
					if (kontLeb2 > 0){
						ostopoak[i + 1].y0++;
						ostopoak[i + 1].y1++;
						kontLeb1--;
					}
				}
			}
			
			ondo = 0;
			jarraitu = 0;
			if (ostopoak[i].kolorea == MOREA_BOTOIA2){
				for (t = 0; t < 20; t++){
					if ((objetuak[ostopoak[i].x0 + t][ostopoak[i].y0 - 1] == HARRI_BOROBILA) || (objetuak[ostopoak[i].x0 + t][ostopoak[i].y0 - 1] == HARRI_KOLOREA) || ((ostopoak[i].x0 + t == posizioGorria.x) && (ostopoak[i].y0 - 1 - ERRADIOBOLA == posizioGorria.y)) || ((ostopoak[i].x0 + t == posizioUrdina.x) && (ostopoak[i].y0 - 1 - ERRADIOBOLA == posizioUrdina.y))){
						jarraitu = 1;
						printf("!");
					}
				}
				if (jarraitu == 1){
					//ostopoak[i].y0 = ostopoak[i].y1 - 5;
					if (kontLeb1 < 75){
						ostopoak[i + 1].y0--;
						ostopoak[i + 1].y1--;
						kontLeb1++;
					}
				}
				if (jarraitu == 0){
					//ostopoak[i].y0 = ostopoak[i].y1 - 10;
					if (kontLeb1 >= 0){
						ostopoak[i + 1].y0++;
						ostopoak[i + 1].y1++;
						kontLeb1--;
					}
				}
			}

			/*
			ondo = 0;
			if (ostopoak[i].kolorea == MOREA_PLATAFORMA1){

			}

			ondo = 0;
			if (ostopoak[i].kolorea == MOREA_PLATAFORMA2){

			}
			*/
		}

		_sleep(10);

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
		emaitza = 0;
		if (controls.keyboard.intro == TRUE){
			emaitza = ERREALITATE_FISIKOA_pantailaGeratu();
			if (emaitza == 1){
				jokalariak[0].pantailaEgoerak[pantaila] = JOLASTEN;
			}
			if (emaitza == 2){
				jokalariak[0].pantailaEgoerak[pantaila] = BERRIZHASI;
			}
			if (emaitza == 3){
				jokalariak[0].pantailaEgoerak[pantaila] = AMAITUGABE;
			}
		}
	
			
	} while (jokalariak[0].pantailaEgoerak[pantaila] == JOLASTEN);

	//return
	return emaitza;
}

int ERREALITATE_FISIKOA_pantailaGeratu(){
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
			if (posizioa < 3){
				posizioa = posizioa + 1;
			}
		}

		ERREALITATE_FISIKOA_pantailaGeratuPrintatu(130, 140 + 50 * posizioa, 200, 30);

		if (tekla == TECLA_RETURN){
			bukatu = 1;
		}

		_sleep(20);

	} while (bukatu == 0);

	//return
	return posizioa;
}

void ERREALITATE_FISIKOA_pantailaGeratuPrintatu(int x, int y, int zabalera, int altuera){
	//aldagaiak
	int i = 0, t = 0;

	//programa

	borraCopiaPantalla();
	JOKOA_pantailaZuriz();
	for (i = y; i < y + altuera; i++){
		for (t = x; t < x + zabalera; t++){
			plot(t, i, HORIA);
		}
	}
	escribirTexto(225, 50, TITULOA);
	escribirTexto(150, 200, SEGI);
	escribirTexto(150, 250, BERRIZSAIATU);
	escribirTexto(150, 300, EXIT);
	actualizaPantalla();
}

int ERREALITATE_FISIKOA_pantailaBukaera(){
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
			if (posizioa < 3){
				posizioa = posizioa + 1;
			}
		}

		ERREALITATE_FISIKOA_pantailaBukaeraPrintatu(130, 140 + 50 * posizioa, 200, 30);


		if (tekla == TECLA_RETURN){
			bukatu = 1;
		}

		_sleep(10);

	} while (bukatu == 0);

	//return
	return posizioa;
}

void ERREALITATE_FISIKOA_pantailaBukaeraPrintatu(int x, int y, int zabalera, int altuera){
	//aldagaiak
	int i = 0, t = 0;

	//programa

	borraCopiaPantalla();
	JOKOA_pantailaZuriz();
	for (i = y; i < y + altuera; i++){
		for (t = x; t < x + zabalera; t++){
			plot(t, i, HORIA);
		}
	}
	escribirTexto(225, 50, TITULOA);
	escribirTexto(150, 200, URRENGOPANTAILA);
	escribirTexto(150, 250, BERRIZSAIATU);
	escribirTexto(150, 300, EXIT);
	actualizaPantalla();
}

int ERREALITATE_FISIKOA_pantailaBukaeraHil(){
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
			if (posizioa < 2){
				posizioa = posizioa + 1;
			}
		}

		ERREALITATE_FISIKOA_pantailaBukaeraHilPrintatu(130, 140 + 50 * posizioa, 200, 30);

		if (tekla == TECLA_RETURN){
			bukatu = 1;
		}

		_sleep(10);

	} while (bukatu == 0);

	//return
	return posizioa;
}

void ERREALITATE_FISIKOA_pantailaBukaeraHilPrintatu(int x, int y, int zabalera, int altuera){
	//aldagaiak
	int i = 0, t = 0;

	//programa

	borraCopiaPantalla();
	JOKOA_pantailaZuriz();
	for (i = y; i < y + altuera; i++){
		for (t = x; t < x + zabalera; t++){
			plot(t, i, HORIA);
		}
	}
	escribirTexto(225, 50, TITULOA);
	escribirTexto(150, 200, BERRIZSAIATU);
	escribirTexto(150, 250, EXIT);
	actualizaPantalla();
}