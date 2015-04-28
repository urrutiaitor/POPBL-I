#ifndef OROKORRAK_H
#define OROKORRAK_H

#ifndef BOOLEANS
#define BOOLEANS

#define ERRADIOBOLA 20
#define OSTOPOKOPURUA 30
#define JOKALARIKOPURUA 1
#define PANTAILAKOPURUA 5

//koloreak
#define BELTZA 0
#define BERDE_ILUNA 26112
#define MARROIA 6697728
#define ZURIA 16777215
#define HORIA 65535
#define BERDEA 6723840
#define URDINA 255
#define GORRIA 16711680
#define TURKESA 16776960
#define MAGENTA 16711935
#define HARRI_KOLOREA 10066329
#define HARRI_BOROBILA 4473924
#define MOREA 10027110
//ateen koloreak
#define URDINA2 400
#define GORRIA2 12255232
//diamanteen koloreak
#define DIAMANTE_GORRIA 16724787
#define DIAMANTE_URDINA 13311

//grisak
#define GRIS2 15658734
#define GRIS1 14546253
#define GRIS3 13421772
#define GRIS4 12303291
#define GRIS5 11184810

typedef enum{
	FALSE, TRUE
}BOOLEAN;
#endif

typedef enum{
	JOLASTEN,
	AMAITUTA,
	AMAITUGABE,
}EGOERA;

typedef struct {
	EGOERA pantailaEgoerak[PANTAILAKOPURUA];
	char izena[30];
	int puntuazioa;
}JOKALARIA;

typedef struct {
	int x;
	int y;
	int talkaPuntua;
}TALKAPOSIZIOA;

typedef struct {
	int x0;
	int y0;
	int x1;
	int y1;
	int kolorea;
}OSTOPOA;

int objetuak[640][480];
OSTOPOA ostopoak[OSTOPOKOPURUA];
JOKALARIA jokalariak[JOKALARIKOPURUA];

#endif
