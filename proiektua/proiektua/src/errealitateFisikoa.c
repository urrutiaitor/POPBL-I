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

	int goraGorria = 0, goraUrdina = 0, eskumaGorria = 0, eskumaUrdina = 0, ezkerraGorria = 0, ezkerraUrdina = 0;
	int tGoraGorria = 0, tGoraUrdina = 0, tEskumaGorria = 0, tEskumaGoraUrdina = 0, tEzkerraGorria = 0, tEzkerraGoraUrdina = 0;
	int dGoraGorria = 0, dGoraUrdina = 0, dEskumaGorria = 0, dEskumaGoraUrdina = 0, dEzkerraGorria = 0, dEzkerraGoraUrdina = 0;
	int amaitutaGoraGorria = 0, amaitutaGoraUrdina = 0, amaitutaEskumaGorria = 0, amaitutaEskumaGoraUrdina = 0, amaitutaEzkerraGorria = 0, amaitutaEzkerraGoraUrdina = 0;

	int ilara = 0, zutabea = 0;
	int objetua = -1;
	int objetuak[640][480];
	int talka = 0;

	POSIZIOA kolisioPuntuaGorria;
	POSIZIOA kolisioPuntuaUrdina;
	POSIZIOA objetuaGorria;
	POSIZIOA objetuaUrdina;

	C controls = { FALSE };

	//programa



	do{
		

		//TALKAK
		for (ilara = -ERRADIOBOLA; ilara < ERRADIOBOLA; ilara++){
			for (zutabea = -ERRADIOBOLA; zutabea < ERRADIOBOLA; zutabea++){
				if ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA)){
					objetua = PANTAILA0_pantailakoObjetuakKonprobatu(zutabea + posizioGorria.x, ilara + posizioGorria.y);

					if (objetua == BELTZA){
						kolisioPuntuaGorria.x = zutabea;
						kolisioPuntuaGorria.y = ilara;
					}
				}
			}
		}

		for (ilara = -ERRADIOBOLA; ilara < ERRADIOBOLA; ilara++){
			for (zutabea = -ERRADIOBOLA; zutabea < ERRADIOBOLA; zutabea++){
				if ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA)){
					objetua = PANTAILA0_pantailakoObjetuakKonprobatu(zutabea + posizioUrdina.x, ilara + posizioUrdina.y);

					if (objetua == BELTZA){
						kolisioPuntuaUrdina.x = zutabea;
						kolisioPuntuaUrdina.y = ilara;
					}
				}
			}
		}

		//GRABITATEA
		if (kolisioPuntuaGorria.y == -ERRADIOBOLA){
			posizioGorria.y = posizioGorria.y - 1;
		}

		if (kolisioPuntuaUrdina.y == -ERRADIOBOLA){
			posizioUrdina.y = posizioUrdina.y - 1;
		}

		//BOLA GORRIAREN MUGIMENDUAK

		//gora

		if (goraGorria == 0){
			if (tekla == TECLA_UP){
				goraGorria = 1;
				tGoraGorria = 0;
			}
		}

		if (goraGorria == 1){
			if (tGoraGorria <= 100){
				//hemen egin behar da mugimendua
				dGoraGorria = ERREALITATE_FISIKOA_mugimenduenDistantziak(tGoraGorria);
				posizioGorria.y = posizioGorria.y - dGoraGorria;
				tGoraGorria++;
			}
			else{
				goraGorria = 0;
			}
		}

		//behera

		if (goraGorria == 0){
			
		}

		//eskuma

		if (eskumaGorria == 0){
			if (tekla == TECLA_RIGHT){
				eskumaGorria = 1;
				tEskumaGorria = 0;
			}
		}

		if (eskumaGorria == 1){
			if (tEskumaGorria <= 50){
				//hemen egin behar da mugimendua
				dEskumaGorria = ERREALITATE_FISIKOA_mugimenduenDistantziak(tEskumaGorria);
				posizioGorria.x = posizioGorria.y + dEskumaGorria;
				tEskumaGorria++;
			}
			else{
				eskumaGorria = 0;
			}
		}

		//ezkerra

		if (ezkerraGorria == 0){
			if (tekla == TECLA_LEFT){
				ezkerraGorria = 1;
				tEzkerraGorria = 0;
			}
		}

		if (ezkerraGorria == 1){
			if (tEzkerraGorria <= 50){
				//hemen egin behar da mugimendua
				dEzkerraGorria = ERREALITATE_FISIKOA_mugimenduenDistantziak(tEzkerraGorria);
				posizioGorria.x = posizioGorria.x - dEzkerraGorria;
				tEzkerraGorria++;
			}
			else{
				ezkerraGorria = 0;
			}
		}



		

		borraCopiaPantalla();
		JOKOA_zelaiaMargotu(pantaila);
		JOKOA_zirkuluUrdinaBistaratu(posizioUrdina.x, posizioUrdina.y);
		JOKOA_zirkuluGorriaBistaratu(posizioGorria.x, posizioGorria.y);
		actualizaPantalla();


	} while (amaituta == 0);






	/*

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

			//objetua = PANTAILA0_pantailakoObjetuakKonprobatu(x0,y0);
			dGorria = 0.5*GKONSTANTEA*tGorria*tGorria;
			if (tGorria >= 50){
				posizioGorria.y = posizioGorria.y + 1; //1 dagoen lekuan dGorria jarri beharko litzateke
			}
			tGorria++;

		}

		if (tekla == TECLA_LEFT){
			posizioGorria.x = posizioGorria.x - MUGIMENDUA;
		}
		if (tekla == TECLA_RIGHT){
			posizioGorria.x = posizioGorria.x + MUGIMENDUA;
		}

		// objetuak[640][480] hasieratzeko
		for (ilara = 0; ilara < 480; ilara++){
			for (zutabea = 0; zutabea < 640; zutabea++){
				objetuak[zutabea][ilara] = -1;
			}
		}


		//talkak egiteko
		talka = 0;

		for (ilara = -ERRADIOBOLA; ilara < ERRADIOBOLA; ilara++){
			for (zutabea = -ERRADIOBOLA; zutabea < ERRADIOBOLA; zutabea++){
				if ((ilara*ilara) + (zutabea*zutabea) <= (ERRADIOBOLA*ERRADIOBOLA)){
					objetuak[posizioGorria.x + zutabea][posizioGorria.y + ilara] = PANTAILA0_pantailakoObjetuakKonprobatu(posizioGorria.x + zutabea, posizioGorria.y + ilara);
					if (objetuak[posizioGorria.x + zutabea][posizioGorria.y + ilara] == BELTZA){
						objetuaGorria.x = posizioGorria.x + zutabea;
						objetuaGorria.y = posizioGorria.y + ilara;
						talka = 1;
					}
				}
			}
		}

		if (talka == 1){
			posizioGorria = posizioInizialaGorria;
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

	*/
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