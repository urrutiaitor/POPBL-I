#ifndef SAGUA_H
#define SAGUA_H

#ifndef SAGUA_C
	#define PUB_SAGUA extern
#else
	#define PUB_SAGUA 
#endif

typedef struct{
	int x;
	int y;
}SAGUA;

PUB_SAGUA SAGUA sagua;

PUB_SAGUA SAGUA irakurriSagua();

#endif