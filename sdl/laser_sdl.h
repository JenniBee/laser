#ifndef _SDL_H_
#define _SDL_H_

#include <roms.h>

typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int    UINT32;
typedef signed char     INT8;
typedef signed short    INT16;
typedef signed int      INT32;
typedef unsigned short  uint16;

SDL_Surface *screen;

Uint32 colour[3]; //yes, i am australian, its COLOUR DAMN IT >_<
extern Uint8 *keystate;
void putpixel(SDL_Surface *surface, int x, int y, int c);

int loadRoms(tagRomList *gameRom);
void pal(int index, int r, int g, int b);
void usage();
void exit_msg();                        /* display exit message */
void exit_laser(int code);              /* exit the program */
void pause_laser();                           /* pause game */
void sys_interrupt();
char *get_keyboard(void);
int main(int argc, char *argv[]);
int FindOption(char *option, int p, int h, int u, int argc, char **argv);
int machine_init();
int machine_gfx(int w, int h);

#endif
