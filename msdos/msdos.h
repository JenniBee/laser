#ifndef _MSDOS_H_
#define _MSDOS_H_

#include <roms.h>

typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int    UINT32;
typedef signed char     INT8;
typedef signed short    INT16;
typedef signed int      INT32;
typedef unsigned short  uint16;

int msdos_set;

int loadRoms(tagRomList *gameRom);
void pal(int index, char r, char g, char b);
void usage();
void exit_msg();                        /* display exit message */
void exit_laser(int code);              /* exit the program */
void pause_laser();                           /* pause game */
void sys_interrupt();
int get_keyboard(int sc);
int main(int argc, char *argv[]);
int FindOption(char *option, int p, int h, int u, int argc, char **argv);
int machine_init(void (*proc)());
int machine_gfx(int w, int h);

#endif
