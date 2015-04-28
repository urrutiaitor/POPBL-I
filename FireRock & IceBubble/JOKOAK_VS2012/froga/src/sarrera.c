#include "orokorrak.h"
#include "sarrera.h"
#include "soinua.h"


#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "text.h"

void SARRERA_mezuaIdatzi();

void SARRERA_intro(){
	BOOLEAN bukatu = FALSE;
	int tekla = 0;
	int idAudio = -1;
	
	idAudio = playAudio(SARRERA_SOUND,  1);
	SARRERA_mezuaIdatzi();
	do{
		tekla = ebentoaEntzun();
		if (tekla == TECLA_RETURN){
			bukatu = TRUE;
		}
	}while(!bukatu);
	removeAudio(idAudio);
	borraCopiaPantalla();
	actualizaPantalla();
}

void SARRERA_mezuaIdatzi(){
	borraCopiaPantalla();
	escribirTexto(225,200,ONGI_ETORRI_MZEUA);
	actualizaPantalla();
}