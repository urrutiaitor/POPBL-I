#ifndef JOKOA_H
#define JOKOA_H

#define JOKOA_SOUND ".\\132TRANCE_02.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\invader.bmp"

typedef enum{IRUDIA, MARGOA, TESTUA}MOTA;


typedef struct{
	POSIZIOA pos;
	int id;
	MOTA mota;
}JOKO_ELEMENTUA;

EGOERA JOKOA_jokoa();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria , JOKO_ELEMENTUA oztopoa);

#endif