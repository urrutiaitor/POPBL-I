#define SOINUA_C
#include "soinua.h"
#include "SDL.h"

int searchAudioPos(int id);
void mixaudio(void *unused, unsigned char *stream, int len);

void mixaudio(void *unused, unsigned char *stream, int len){
	int i;
    unsigned int amount;

    for ( i=0; i<SOINU_KOPURUA; ++i ) {
        amount = (soinuak[i].dlen-soinuak[i].dpos);
        if ( amount > len ) {
            amount = len;
        }
        SDL_MixAudio(stream, &soinuak[i].data[soinuak[i].dpos], amount, SDL_MIX_MAXVOLUME);
        soinuak[i].dpos += amount;
    }
	 for ( i=0; i<SOINU_KOPURUA; ++i ) {
		 if ( soinuak[i].dpos == soinuak[i].dlen ){
			 if (soinuak[i].isLoop){
				soinuak[i].dpos = 0;
			 }
		 }
	 }
	//LOOP DIREN EDO EZ HEMEN EZARRI EGITEN DITUGU BERAIEN POSIZIOAK ETA KITTO
}

void audioInit(){
	extern void mixaudio(void *unused, Uint8 *stream, int len);
    SDL_AudioSpec fmt;
	int i = 0;

    /* Set 16-bit stereo audio at 22Khz */
    fmt.freq = 22050;
    fmt.format = AUDIO_S16;
    fmt.channels = 2;
    fmt.samples = 512;        /* A good value for games */
    fmt.callback = mixaudio;
    fmt.userdata = NULL;

    /* Open the audio device and start playing sound! */
    if ( SDL_OpenAudio(&fmt, NULL) < 0 ) {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(1);
	}else{
		SDL_PauseAudio(0);
	}
	
}

int playAudio(char *file, int loop){
	int index;
    SDL_AudioSpec wave;
    Uint8 *data;
    Uint32 dlen;
    SDL_AudioCVT cvt;

    /* Look for an empty (or finished) sound slot */
    for ( index=0; index<SOINU_KOPURUA; ++index ) {
		if ( soinuak[index].dpos == soinuak[index].dlen  && !soinuak[index].isLoop) {
            break;
        }
    }
    if ( index == SOINU_KOPURUA )
        return;

    /* Load the sound file and convert it to 16-bit stereo at 22kHz */
    if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
        fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
        return;
    }
    SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq,
                            AUDIO_S16,   2,             22050);
    
	cvt.buf =(Uint8*) ( malloc(dlen*cvt.len_mult));
    memcpy(cvt.buf, data, dlen);
    cvt.len = dlen;
    SDL_ConvertAudio(&cvt);
    SDL_FreeWAV(data);

    /* Put the sound data in the slot (it starts playing immediately) */
    if ( soinuak[index].data ) {
        free(soinuak[index].data);
    }
    SDL_LockAudio();
	soinuak[index].id = index;
    soinuak[index].data = cvt.buf;
    soinuak[index].dlen = cvt.len_cvt;
    soinuak[index].dpos = 0;
	if (loop){
		soinuak[index].isLoop = 1;
	}else{
		soinuak[index].isLoop = 0;
	}
    SDL_UnlockAudio();
	return index;
}
void audioTerminate(){
	 SDL_CloseAudio();
}

void removeAudio(int id){
	int i = 0;
	int pos =  0;

	pos = searchAudioPos(id);
	SDL_LockAudio();
	for (i = pos ; i < SOINU_KOPURUA-1 ; i++){
		soinuak[i] = soinuak[i+1];
	}
	soinuak[i+1].id = -1;
    soinuak[i+1].data = NULL;
    soinuak[i+1].dlen = 0;
    soinuak[i+1].dpos = 0;
	soinuak[i+1].isLoop = 0;
	SDL_UnlockAudio();
}

int searchAudioPos(int id){
	int i = 0;
	int ret = -1;
	int irten = 0;
	do{
		if ( soinuak[i].id == id ){
			irten = 1;
			ret = i;
		}else{
			i++;
		}
		
	}while( (i < SOINU_KOPURUA) && ( irten == 0) );

	return ret;
}