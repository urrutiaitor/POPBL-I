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
#define MOREA_BOTOIA1 10027110
#define MOREA_PLATAFORMA1 10040166
#define MOREA_BOTOIA2 16751052
#define MOREA_PLATAFORMA2 16751103
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

//fondo
#define BLOKEA_FONDO 138192914
#define BERDEA_FONDO -1853561046
#define URDINA_FONDO -1253861942
#define GORRIA_FONDO -1934484702

#define TITULOA "FireRock & IceBubble"
#define JOKOA "Jokoa"
#define AZALPENA "Jokoaren azalpena"
#define RANKING "Ranking-a"
#define KREDITUAK "Kredituak"
#define SEGI "Pantailan segi egin"
#define BERRIZSAIATU "Pantaila hasieratik hasi"
#define URRENGOPANTAILA "Urrengo pantailara joan"
#define EXIT "Irten"

#define AUKERA0 "0. Pertsonaiaren mugimenduak probatu"
#define AUKERA1 "1. Pantaila"
#define AUKERA2 "2. Pantaila"
#define AUKERA3 "3. Pantaila"
#define AUKERA4 "4. Pantaila"
#define AUKERA5 "5. Pantaila"

#define IZENA1 "Aitor Urrutia Zubikarai"
#define IZENA2 "Ane Perez de Arenaza"
#define IZENA3 "Garbiñe Ugarte"
#define IZENA4 "Irati Alustiza"

typedef enum{
	FALSE, TRUE
}BOOLEAN;
#endif

typedef enum{
	JOLASTEN,
	AMAITUTA,
	AMAITUGABE,
	BERRIZHASI
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
	TALKAPOSIZIOA talkaPosizioak[400];	
}OSTOPOA;

typedef struct {
	int x;
	int y;
	int inertziaY;
	int inertziaX;
}POSIZIOA;

POSIZIOA posizioGorria;
POSIZIOA posizioUrdina;

int objetuak[640][480];
OSTOPOA ostopoak[OSTOPOKOPURUA];
JOKALARIA jokalariak[JOKALARIKOPURUA];


#endif
