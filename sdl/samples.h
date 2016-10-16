#ifndef _SAMPLES_H_
#define _SAMPLES_H_

#include <signal.h>

typedef struct {
	SDL_AudioSpec spec;
	Uint32 length;
	Uint8 *buffer;
	int pos;
}wave;

int init_sound();
void shutdown_sound();
void fill_audio(void *unused, Uint8 *stream, int len);
wave *load_wav( const char *file );
void unload_wav(wave *wav);
void play_wav(wave *wav, int n, int loop);
void stop_wav(int n);

int laser_volume;
int sound_enable;
SDL_AudioSpec audio;

#endif /* _SAMPLES_H_ */
