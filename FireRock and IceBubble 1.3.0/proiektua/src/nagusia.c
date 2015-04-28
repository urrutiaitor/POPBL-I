#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"
#include "sistemaGrafikoa.h"


int main(){
	//aldagaiak
	int aukera = 0;
	int pantaila = 0;
	int irten = 0;

	//programa
	BOOLEAN jarraitu = FALSE;
	EGOERA egoera;
	SISTEMA_GRAFIKOA_hasieratu();

	do{

		aukera = SARRERA_aukerakAukeratu();

		switch (aukera){

		case 1: //jokoko pantailak

			pantaila = SARRERA_pantailakAukeratu();

			switch (pantaila){
			case 1: //bolaren mugimenduak

				egoera = PANTAILA0_nagusia();
				break;

			case 2: //1. pantaila

				egoera = PANTAILA1_nagusia();
				break;

			case 3: //2.pantaila

				egoera = PANTAILA2_nagusia();
				break;

			case 4: //3.pantaila

				egoera = PANTAILA3_nagusia();
				break;

			case 5: //4.pantaila

				egoera = PANTAILA4_nagusia();
				break;


			case 6: //4.pantaila

				//egoera = PANTAILA5_nagusia();
				break;
			}
			
			break;

		case 2: //jokoaren azalpena

			break;

		case 3: //ranking

			break;

		case 4: //kredituak
			SARRERA_kredituak();
			break;


		case 5: //irten
			irten = 1;
			break;
		}

	} while (irten == 0);


	SISTEMA_GRAFIKOA_bukatu();
}
	