#ifndef OROKORRAK_H
#define OROKORRAK_H

#ifndef BOOLEANS
#define BOOLEANS
typedef enum{
	FALSE, TRUE
}BOOLEAN;
#endif

typedef enum{
	JOLASTEN,
	GALDU,
	IRABAZI,
}EGOERA;

typedef struct {
	int x;
	int y;
	int talkaPuntua;
}TALKAPOSIZIOA;

#define ERRADIOBOLA 20

//koloreak
#define BELTZA 0
#define ZURIA 16777215
#define HORIA 65535
#define BERDEA 65280
#define URDINA 255
#define GORRIA 16711680
#define TURKESA 16776960
#define MAGENTA 16711935

int objetuak[640][480];

#endif
