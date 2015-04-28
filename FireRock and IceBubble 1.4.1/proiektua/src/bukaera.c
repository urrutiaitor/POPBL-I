#include "orokorrak.h"
#include "bukaera.h"


#include "NewTypes.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"

void BUKAERA_irudiaBistaratu();

BOOLEAN  BUKAERA_menua(EGOERA egoera){
	/*
	BOOLEAN bukatu = FALSE;
	int tekla = 0;
	int idAudio1 = -1, idAudio2 = -1, idAudioGame;
	
	idAudio1 = playAudio(BUKAERA_SOUND_1,  1);
	if (egoera ==IRABAZI){
		idAudioGame = playAudio(JOKOA_SOUND_WIN,  0);
	}else{
		idAudioGame = playAudio(JOKOA_SOUND_LOOSE,  0);
	}
	BUKAERA_irudiaBistaratu();
	do{

		tekla = ebentoaEntzun();
		if (tekla == TECLA_RETURN){
			bukatu = TRUE;
		}
	}while(!bukatu);
	removeAudio(idAudio1);
	removeAudio(idAudio2);
	return FALSE;
	*/
}

void BUKAERA_irudiaBistaratu(){
	int martzianoId = -1;
	martzianoId= insertaImagen(BUKAERA_IMAGE);
	actualizaPosicionImagen( martzianoId, 200 , 200); 
	borraCopiaPantalla();
	pintaImagenes();
	actualizaPantalla();
}