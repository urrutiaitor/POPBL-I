#ifndef SOINUA_H
#define SOINUA_H

#ifndef SOINUA_C
	#define PUB_SOINUA extern
#else
	#define PUB_SOINUA 
#endif


#define SOINU_KOPURUA 10

typedef struct sample {
	int id;
    unsigned char *data;
    unsigned int dpos;
    unsigned int dlen;
	int active;
	int isLoop;
} SOINUA;
	
PUB_SOINUA SOINUA soinuak[SOINU_KOPURUA];

void audioInit();
int playAudio(char *file, int loop);
void audioTerminate();
void removeAudio(int id);


#endif