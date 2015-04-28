#include "sistemaGrafikoa.h"

#include <stdio.h>

#include "NewTypes.h"
#include "graphics.h"
#include "soinua.h"

void SISTEMA_GRAFIKOA_hasieratu(){
	if  ( inicializaSistemaGrafico() == -1 ){
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		exit(1);
	}else{
		 audioInit();
	}
}

void SISTEMA_GRAFIKOA_bukatu(){
	audioTerminate();
	finalizaSistemaGrafico();
}