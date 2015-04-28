#include "errealitateFisikoa.h"


POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa){
	posizioa.y = posizioa.y + 1;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}