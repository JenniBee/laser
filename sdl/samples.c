#include "laser.h"

int queue;
int queue_use;
int sample_loop;
int use_loop=0;

int init_sound() {
	SDL_AudioSpec adevice;
	if(ldebug) printf("Debug: Initializing audio device...\r\n");

	if(SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
		if(ldebug) printf("Debug: Unable to load Audio subsystem: %s\r\n", SDL_GetError());
		return(-1);
	}

	adevice.channels = 1;
	adevice.format = AUDIO_U8;
	adevice.freq = 11025;
	adevice.samples = 512;
	adevice.callback = fill_audio;
	adevice.userdata = NULL;

	if(SDL_OpenAudio(&adevice, NULL) != 0) {
		if(ldebug) printf("Debug: Unable to open audio device: %s\r\n", SDL_GetError());
		return 1;
	}

	if(ldebug) printf("Debug: Audio device Initialized\r\n");
        return(0);
}

void shutdown_sound() {
	SDL_Delay(100);
	SDL_CloseAudio();
}

extern wave *samples[];
// borrowed from some example somewhere, 
void fill_audio(void *unused, Uint8 *stream, int len) {
	Uint8 *waveptr;
	int    waveleft;

	/* Set up the pointers */
	waveptr = samples[queue]->buffer + samples[queue]->pos;
	waveleft = samples[queue]->length - samples[queue]->pos;

 	/* Go! */
	if (waveleft <= len){
		SDL_PauseAudio(1);
	} else {
		SDL_MixAudio(stream, waveptr, len, SDL_MIX_MAXVOLUME);
		samples[queue]->pos += len;
	}

	queue_use=0;
	//if(ldebug) printf("Debug: Audio played..\r\n");
}

wave *load_wav( const char *file ) {
	wave *load;

	load = malloc(sizeof(wave));
	if(ldebug) printf("Debug: Loading wave file: %s\r\n", file);
	if(SDL_LoadWAV(file,&load->spec,&load->buffer, &load->length) == NULL) {
		if(ldebug) printf("Debug: Unable to open wave file: %s\r\n",file);
		return NULL;
	}

	if(ldebug) printf("Debug: %s loaded\r\n", file);
	load->pos = 0;
	load->spec.callback = fill_audio;
	return load;
}

void unload_wav(wave *wav) {
	SDL_FreeWAV(wav->buffer);
}

void play_wav(wave *wav, int n, int loop) {
	queue = n;
	queue_use = 1;
	sample_loop = loop;
	use_loop = 1;
	samples[queue]->pos = 0;
	SDL_PauseAudio(0);
}

void stop_wav(int n) {
	sample_loop = 0;
	use_loop = 1;
}
