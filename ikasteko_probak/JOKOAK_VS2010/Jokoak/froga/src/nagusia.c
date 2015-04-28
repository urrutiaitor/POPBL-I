#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"
#include "sistemaGrafikoa.h"


int main(){
	BOOLEAN jarraitu = FALSE;
	EGOERA egoera;
	SISTEMA_GRAFIKOA_hasieratu();
	do{
		SARRERA_intro();
		egoera = JOKOA_jokoa();
		jarraitu = BUKAERA_menua(egoera);
	}while(jarraitu);
	SISTEMA_GRAFIKOA_bukatu();
}
	