/* WARNING: This file is OBSOLETE, it is NOT used any more
 * and is only provided with the distribution for REFERENCE
 * purposes only. Please refrain from linking this file to
 * the main package.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "z80.h"
#include <allegro.h>

#define XLEN 256
#define YLEN 256

extern volatile byte IType;
extern int  ICount;
int si2tester = 0;
int bwtester = 0;
int boothilltester = 0;
int bowlingtester = 0;
int lupintester = 0;
int horizontaltester = 0;
int joysticktester = 0;
int soundtester = 0;
int checktester = 0;
int clownstester = 0;
int spcking2tester = 0;
int christmastester = 0;

SAMPLE *shot;
SAMPLE *saucer;
SAMPLE *basehit;
SAMPLE *invaderhit;
SAMPLE *bonus;
SAMPLE *fleet1;
SAMPLE *fleet2;
SAMPLE *fleet3;
SAMPLE *fleet4;
SAMPLE *saucerhit;
SAMPLE *jinglebells;

int vol = 255;

void NMI()
  {
  IFlag = 1;
  IType = (IType == 1 ? 2 : 1);
  }

END_OF_FUNCTION(NMI);

void pal(int index, char r, char g, char b);

void ShowHelp()
{
        printf("Laser 0.13.  Based on SinVader by Mike Green\n");
        printf("Usage:     laser gamename [options]\n");
        printf("Options:   -?,-h        Show this help text\n");
        exit(0);
}

int FindOption(char *option, int p, int h, int u, int argc, char **argv)
{
        static int      t[] = { 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0 };
        int             i;
        char            *c;
      
        if (argc > 128)
                argc = 128;     /* maximum this function can handle is 128 */

        /*
         * if p = 1 and h = 0 will find option and return decimal value of
         * argv[i+1], if h = 1 will read it as hex.
         * if p = 0 then it will return index of option in argv[], 0 not found
         * if u = 1 will return index of first occurance of untouched option
         */

        if (u)  /* find first untouched element */
        {
                for (i = 1; i < argc; i++)
                {
                        if (!t[i])      /* 0 indicates untouched */
                                return i;
                }
                return 0;
        }

        if (p)  /* find option and return integer value following it */
        {
                for (i = 1; i < argc; i++)
                {                
                        if (strcmp(argv[i], option) == 0)       /* found */
                        {
                                if (i >= argc)                  /* bounds! */
                                        return 0;
                                t[i + 1] = t[i] = 1;            /* touched */
                                if (!h)
                                        return atoi(argv[i + 1]);
                                else
                                        return strtoul(argv[i + 1], &c, 16);
                        }
                }
                return 0;                                       /* no match */
        }
        else    /* find option and return position */        
        {
                for (i = 1; i < argc; i++)
                {                
                        if (strcmp(argv[i], option) == 0)
                        {
                                t[i] = 1;
                                return i;       /* found! return position */
                        }
                }                                                          
                return 0;
        }
        return 0;
}

int i;
int numbo=0;
byte bGame;
reg z80reg;
byte *pbROM;
byte *pbRAM;
byte bShiftValue = 0;
byte bBitmap = 0;
byte bBitmapPrevious = 0;
DATAFILE *audio;
char *gameRam; // 64K RAM for the game.

byte *RAM;
PALLETE invaders; 
reg R;
FILE *in;
BITMAP *buffer;

int colf[10],colb[10]={16,32,48,64,80,96,112,128,144,160};

int main(int argc, char **argv)
{

  if (FindOption("-joy", 0, 0, 0, argc, argv))
  {
  joysticktester = 1;
  }
             
  if (FindOption("-sound", 0, 0, 0, argc, argv))
  {
  soundtester = 1;
  }

  if (FindOption("-bahhumbug", 0, 0, 0, argc, argv))
  {
  christmastester = 1;
  }


	/* check command line for no options, process help */
        if (argc == 1)                                  /* show help */
                ShowHelp();
        if (FindOption("-?", 0, 0, 0, argc, argv) ||
            FindOption("-h", 0, 0, 0, argc, argv))
                ShowHelp();

        
	allegro_init(); 
        set_gfx_mode(GFX_MODEX,256,256,0,0);

        pal(1, 63,  0,  0); // Red
        pal(2,  0, 63,  0); // Green
        pal(3, 63, 63, 63); // White
 	install_timer();
	install_keyboard();
        if(soundtester == 1)
        {
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0) != 0) {
        printf("*ERROR* initialising sound system\n%s\n", allegro_error);
	allegro_exit();
        }
        }

        if(joysticktester == 1)
	{
        initialise_joystick();
        }
	set_projection_viewport(0, 0, SCREEN_W, SCREEN_H);
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
   	clear(buffer);	

saucer = load_sample("samples/invaders/0.wav");
shot = load_sample("samples/invaders/1.wav");
basehit = load_sample("samples/invaders/2.wav");
invaderhit = load_sample("samples/invaders/3.wav");
bonus = load_sample("samples/invaders/9.wav");
fleet1 = load_sample("samples/invaders/4.wav");
fleet2 = load_sample("samples/invaders/5.wav");
fleet3 = load_sample("samples/invaders/6.wav");
fleet4 = load_sample("samples/invaders/7.wav");
saucerhit = load_sample("samples/invaders/8.wav");
jinglebells = load_sample("samples/invaders/jingle.wav");

if(christmastester == 1)
{
}

else
{	
play_sample(jinglebells,vol,128,1000,1);
}
	
	/* ok time to load the roms! */
          if (FindOption("invaders", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/invaders/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/invaders/invaders.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/invaders/invaders.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

		  in = fopen("roms/invaders/invaders.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("invdelux", 0, 0, 0, argc, argv))
              {
              si2tester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/invdelux/invdelux.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/invdelux/invdelux.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/invdelux/invdelux.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/invdelux/invdelux.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/invdelux/invdelux.d", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("boothill", 0, 0, 0, argc, argv))
              {

              boothilltester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/boothill/Romh.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/boothill/Romg.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/boothill/Romf.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/boothill/Rome.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }


	  else
          if (FindOption("spaceatt", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/spaceatt/h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/spaceatt/sv02.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/spaceatt/f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
		  
		  in = fopen("roms/spaceatt/c", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spaceatt/b", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spaceatt/a", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("spaceat2", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/spaceat2/Spaceatt.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/spaceat2/Spaceatt.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/spaceat2/Spaceatt.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
		  
		  in = fopen("roms/spaceat2/Spaceatt.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("sinvzen", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/sinvzen/1.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/sinvzen/2.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/sinvzen/3.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
		  
		  in = fopen("roms/sinvzen/4.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvzen/5.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvzen/6.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvzen/7.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvzen/8.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("sinvemag", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/sinvemag/sv0h.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/sinvemag/emag_si.b", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/sinvemag/emag_si.c", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
		  
		  in = fopen("roms/sinvemag/emag_si.d", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvemag/emag_si.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sinvemag/emag_si.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("superinv", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/invaders/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
	  
	      in = fopen("roms/invaders/invaders.g", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/invaders/invaders.f", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		  
		  in = fopen("roms/superinv/02", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/superinv/04", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/superinv/05", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("earthinv", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/earthinv/Earthinv.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/earthinv/Earthinv.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/earthinv/Earthinv.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/earthinv/Earthinv.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("sicv", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/SI_CV/Cv17.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/SI_CV/Cv18.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/SI_CV/Cv19.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/SI_CV/Cv20.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("lrescue", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/lrescue/lrescue.1", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/lrescue/lrescue.2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400


		  in = fopen("roms/lrescue/lrescue.3", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/lrescue/lrescue.4", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/lrescue/lrescue.5", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/lrescue/lrescue.6", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("galxwars", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/galxwars/galxwars.0", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/galxwars/galxwars.1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400


		  in = fopen("roms/galxwars/galxwars.2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/galxwars/galxwars.3", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0C00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/galxwars/galxwars.4", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/galxwars/galxwars.5", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("invrvnge", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/invrvnge/invrvnge.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/invrvnge/invrvnge.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400


		  in = fopen("roms/invrvnge/invrvnge.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/invrvnge/invrvnge.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("destinat", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/destinat/36_h.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/destinat/35_g.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/destinat/34_f.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/destinat/33_e.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/destinat/32_d.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/destinat/31_c.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/destinat/42_b.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x5000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("cosmicmo", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/cosmicmo/cosmicmo.1", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/cosmicmo/cosmicmo.2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400


		  in = fopen("roms/cosmicmo/cosmicmo.3", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/cosmicmo/cosmicmo.4", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0C00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/cosmicmo/cosmicmo.5", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/cosmicmo/cosmicmo.6", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/cosmicmo/cosmicmo.7", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("laser", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/laser/1.u36", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/laser/2.u35", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/laser/3.u34", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/laser/4.u33", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("spceking", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/invaders/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/spceking/spcekng2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/spceking/spcekng3", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/spceking/spcekng4", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("sfeverbw", 0, 0, 0, argc, argv))
              {

              RAM = malloc(0x10000);
	      spcking2tester = 1;

	      in = fopen("roms/sfeverbw/spacefev.f1", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

		  in = fopen("roms/sfeverbw/spacefev.f2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/sfeverbw/spacefev.g1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  in = fopen("roms/sfeverbw/spacefev.g2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sfeverbw/spacefev.h1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  in = fopen("roms/sfeverbw/spacefev.h2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sfeverbw/spacefev.i1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/sfeverbw/spacefev.i2", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00


}

          else
          if (FindOption("spcking2", 0, 0, 0, argc, argv))
              {
		spcking2tester = 1;
              RAM = malloc(0x10000);

	      in = fopen("roms/spcking2/1.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

		  in = fopen("roms/spcking2/2.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/spcking2/3.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/spcking2/4.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spcking2/5.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spcking2/6.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spcking2/c.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

}


          else
          if (FindOption("checkmat", 0, 0, 0, argc, argv))
              {
		checktester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/checkmat/checkmat.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/checkmat/checkmat.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400


		  in = fopen("roms/checkmat/checkmat.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/checkmat/checkmat.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0C00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("spacewr3", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/spcewr3/ic36.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/spcewr3/ic35.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/spcewr3/ic34.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/spcewr3/ic33.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/spcewr3/ic32.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

          else
          if (FindOption("-test", 0, 0, 0, argc, argv))
              {
              horizontaltester = 1;
              RAM = malloc(0x10000);

	      in = fopen("roms/sitv/tv0h.s1", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/sitv/tv02.rp1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/sitv/tv03.n1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  in = fopen("roms/sitv/tv04.m1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

	      in = fopen("roms/invaders/invaders.e", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
              }

          else
          if (FindOption("sitv", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);

	      in = fopen("roms/sitv/tv0h.s1", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/sitv/tv02.rp1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/sitv/tv03.n1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  in = fopen("roms/sitv/tv04.m1", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

	      in = fopen("roms/invaders/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
              }

          else
          if (FindOption("bowler", 0, 0, 0, argc, argv))
              {
              bowlingtester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/bowler/h.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
			
		  in = fopen("roms/bowler/g.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/bowler/f.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/bowler/e.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/bowler/d.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("moonbase", 0, 0, 0, argc, argv))
              {
              si2tester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/moonbase/pv.01", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/moonbase/pv.02", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/moonbase/ze3-5.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/moonbase/ze3-6.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/moonbase/ze3-7.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/moonbase/ze3-8.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/moonbase/ze3-9.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/moonbase/ze3-10.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

              }

	  else
          if (FindOption("starw", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/starw/roma", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/starw/romb", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/starw/romc", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/starw/romd", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/starw/rome", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/starw/romf", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("starw", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/starw/roma", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/starw/romb", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/starw/romc", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/starw/romd", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/starw/rome", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/starw/romf", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("schaser", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/schaser/rt13.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/schaser/rt14.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/schaser/rt15.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/schaser/rt16.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/schaser/rt17.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/schaser/rt18.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/schaser/rt19.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/schaser/rt20.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/schaser/rt21.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/schaser/rt22.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	  else
          if (FindOption("invadpt2", 0, 0, 0, argc, argv))
              {
              si2tester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/invadpt2/pv.01", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/invadpt2/pv.02", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/invadpt2/pv.03", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/invadpt2/pv.04", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/invadpt2/pv.05", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

		  
		  in = fopen("roms/invdelux/invdelux.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/invdelux/invdelux.d", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

	  else
          if (FindOption("clowns", 0, 0, 0, argc, argv))
              {
              clownstester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/clowns/h2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/g2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/f2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/e2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/d2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/c2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1400], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

		  }

	  else
          if (FindOption("yosakdon", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/yosakdon/yd1.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd2.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd3.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd4.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd5.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1400], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd6.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/yosakdon/yd7.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1c00], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

		  }
	  else
          if (FindOption("lupin3", 0, 0, 0, argc, argv))
              {
              lupintester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/lupin3/lp12.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/lupin3/lp13.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/lupin3/lp14.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/lupin3/lp15.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/lupin3/lp16.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

		  
		  in = fopen("roms/lupin3/lp17.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/lupin3/lp18.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x5000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

	  else
          if (FindOption("clowns", 0, 0, 0, argc, argv))
              {
              lupintester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/clowns/h2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/g2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/clowns/f2.cpu", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		
			
		  in = fopen("roms/clowns/e2.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/clowns/d2.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800

		  
		  in = fopen("roms/clowns/c2.cpu", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

	  else
          if (FindOption("maze", 0, 0, 0, argc, argv))
              {

              RAM = malloc(0x10000);
	      in = fopen("roms/maze/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

	      in = fopen("roms/maze/invaders.g", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000
		  }

          else
          if (FindOption("alieninv", 0, 0, 0, argc, argv))
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/alieninv/1h.bin", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/alieninv/1g.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/alieninv/1f.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/alieninv/1e.bin", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

          else
          if (FindOption("ozmawars", 0, 0, 0, argc, argv))
              {
		  bwtester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/ozmawars/mw01", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/ozmawars/mw02", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/ozmawars/mw03", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/ozmawars/mw04", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawars/mw05", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawars/mw06", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

          else
          if (FindOption("solfight", 0, 0, 0, argc, argv))
              {
		  bwtester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/solfight/solfight.m", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/solfight/solfight.n", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/solfight/solfight.p", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/solfight/solfight.r", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawars/mw05", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/solfight/solfight.t", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

          else
          if (FindOption("ozmawar2", 0, 0, 0, argc, argv))
              {
		  bwtester = 1;
              RAM = malloc(0x10000);
	      in = fopen("roms/ozmawars/mw01", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

		  in = fopen("roms/ozmawars/mw02", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400
		  
		  in = fopen("roms/ozmawar2/oz5", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/ozmawar2/oz6", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1400], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawar2/oz7", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawar2/oz8", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawars/mw05", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  in = fopen("roms/ozmawar2/oz11", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4800], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00

		  in = fopen("roms/ozmawar2/oz12", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x4c00], 0x400, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
		  }

          else
              {
              RAM = malloc(0x10000);
	      in = fopen("roms/invaders/invaders.h", "rb"); //read in the invaders ROM in binary mode
	      fread(&RAM[0x0000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0000

			
			
		  in = fopen("roms/invaders/invaders.g", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x0800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0400

		  
		  
		  in = fopen("roms/invaders/invaders.f", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1000], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0800
	  
		  
		  in = fopen("roms/invaders/invaders.e", "rb"); //read in the invaders ROM in binary mode
		  fread(&RAM[0x1800], 0x800, 1, in);  //read in 0x400 bytes at position
	      fclose(in);                         //0x0c00
              }

	LOCK_VARIABLE(IType);
        LOCK_VARIABLE(IFlag);
	LOCK_FUNCTION(NMI);
	install_int(NMI,8);

  clear(screen);                              //and clear the screen


      Z80(R);         //Actually starts the emulation

return 0;
}

void pal(int index, char r, char g, char b)
  {
  outp(0x3c8,index);
  outp(0x3c9,r); outp(0x3c9,g); outp(0x3c9,b);
  }

void M_WRMEM(word A,byte V)
{
int x, y, i, color = 3;
	if ( A < 0x2000)
	{

	return;
	}

	  RAM[A] = V;
	  
  if (A >= 0x2400 && A < 0x4400) // Video RAM...
     {
     // Graphics consist of 3 color bands, White, Red and Green..
     A -= 0x2400;
     y = A - ((x = A / 32) * 32);
     if(horizontaltester == 1)
     {

     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     else
     if(clownstester == 1)
     {
     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     else
     if(boothilltester == 1)
     {
     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     else
     if(checktester == 1)
     {
     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     else
     if(lupintester == 1)
     {
     if (x > 23 && y == 24 && x < 104) color = 1;
     if (x > 23 && y == 21 && x < 104) color = 1;
     if (x > 119 && y == 24 && x < 200) color = 1;
     if (x > 119 && y == 21 && x < 200) color = 1;
     }
     else
     if(bowlingtester == 1)
     {
     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     else
     if(si2tester == 1)
     {
     if (x > 135 && y > 28)            color = 14;  // Yellow 'Score-2' word
     if (x > 61 && x < 150 && y > 28)  color = 1;  // Red 'Taito' word
     if (x > 61 && x < 134 && y > 27 && y < 29)  color = 2;  // Green 'High Score' number
     if (x < 60 && y > 28)             color = 11;  // Light Blue 'Score-1' word
     if (y < 24)            color = 2;  // Green
     if (y < 20)            color = 11;  // Light Blue
     if (y < 16)            color = 5;  // Pink
     if (y < 12)            color = 14; // Yellow
     if (y < 8)            color = 1; 
     if (y < 5)            color = 11;  // Light Blue
     if (y < 4)            color = 1;
     if (y >  23 && y < 28) color = 1;
     if (x <  100 && y <  2) color = 11;  // Light Blue 'ships left' number
     if (x > 135 && x < 182 && y <  2) color = 5;  // Pink 'Credits' word.
     if (x > 135 && x > 182 && y <  2) color = 11;  // Light Blue 'Credits' number.

     }
     else
     if(bwtester == 1)
     {
     if (y < 8)            color = 3;
     if (y >  23 && y < 28) color = 3;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }

     else
     {
     if (y < 8)            color = 2;
     if (y >  23 && y < 28) color = 1;
     if (x <  16 && y <  2) color = 3;  // White 'ships left' number
     if (x > 135 && y <  2) color = 3;  // White 'Credits' word.
     }
     for (i = 0; i < 8; i++)
        if(horizontaltester == 1)
        {
        putpixel(screen, (y * 8 + i), x, (V & (1 << i)) ? color : 0);
        }
        else
        if(clownstester == 1)
        {
        putpixel(screen, (y * 8 + i), x, (V & (1 << i)) ? color : 0);
        }
        else
        if(boothilltester == 1)
        {
        putpixel(screen, (y * 8 + i), x, (V & (1 << i)) ? color : 0);
        }
        else
        if(checktester == 1)
        {
        putpixel(screen, (y * 8 + i), x, (V & (1 << i)) ? color : 0);
        }
	  else
  	  if(bowlingtester == 1)
 	  {
	  putpixel(screen,(256-x),(y * 8 + i),(V & (1 << i)) ? color : 0);
	  }
        else
        {
        putpixel(screen,x,(256-(y * 8 + i)), (V & (1 << i)) ? color : 0);
        }
     }
        
}

byte M_RDMEM(word addr)
  {
  return RAM[addr];
  }

/*** Input/Output values from/to ports: *******************/
/*** These are called on IN and OUT commands and should ***/
/*** supplied by machine-dependent part of the code.    ***/
/**********************************************************/

byte DoIn(byte Port)
{
	word wValue;
	byte bValue;

if(lupintester==1)
{
	switch(Port) {
		case 0:
			return(bValue);
		case 1:
			if (key[KEY_ESC]) 
			{
			clear(screen); 
			set_gfx_mode(GFX_TEXT,80,25,0,0); 
			printf("LASER 0.13\nBased On SinVader by Mike Green.\nZ80 Core by Marat Fayzullin\n");			
			exit(0);
			}
			if(key[KEY_1]) bValue|=0x04;
			if(key[KEY_2]) bValue|=0x02;
			if(key[KEY_3]) bValue&=~0x01;
			if(key[KEY_UP]) bValue|=0x80;
			if(key[KEY_DOWN]) bValue|=0x20;
			if(key[KEY_LEFT]) bValue|=0x40;
			if(key[KEY_RIGHT]) bValue|=0x10;
			if(key[KEY_SPACE]) bValue|=0x08;
			if(key[KEY_P])  // Pause
		        {
		        textprintf_centre(screen, font, 128, 108, makecol(255,255,255), "Paused");
		        while(key[KEY_P]);
		        clear_keybuf();
		        while(!keypressed());
		        clear_keybuf();
		        }
			return(bValue);
		case 3:
			wValue=(bBitmap<<8)|bBitmapPrevious;
			wValue=wValue<<bShiftValue;
			bValue=(byte)(wValue>>8);
			return(bValue);
		default:
			return(0x00);
	}

}

else
{
	switch(Port) {
		case 1:
			bValue=0x81;
                        if(joysticktester == 1)
			{
                        poll_joystick();
			if (joy_left)  bValue|=0x20; 
			if (joy_right) bValue|=0x40; 
			if (joy_b1) bValue|=0x10;
                        }
			if (key[KEY_ESC]) 
			{
			clear(screen); 
			set_gfx_mode(GFX_TEXT,80,25,0,0); 
			printf("LASER 0.10\nBased On SinVader by Mike Green.\nZ80 Core by Marat Fayzullin\n");			
			exit(0);
			}
			if(key[KEY_1]) bValue|=0x04;
			if(key[KEY_2]) bValue|=0x02;
			if(key[KEY_3]) bValue&=~0x01;
			if(key[KEY_LEFT]) bValue|=0x20;
			if(key[KEY_RIGHT]) bValue|=0x40;
			if(key[KEY_SPACE]) bValue|=0x10;
			if(key[KEY_F5]) screen_shot( "screenshot.pcx" );
			if(key[KEY_F12]) save_state();
			if(key[KEY_F11]) load_state();
			if(key[KEY_P])  // Pause
		        {
		        textprintf_centre(screen, font, 128, 108, makecol(255,255,255), "Paused");
		        while(key[KEY_P]);
		        clear_keybuf();
		        while(!keypressed());
		        clear_keybuf();
		        }

  if (key[KEY_PLUS_PAD])
  {
   if (vol < 255) vol++;
   set_volume(vol, 0);
   textprintf(screen, font, 150, 230, 7, "VOL: %d ", vol);
  }

  if (key[KEY_MINUS_PAD])
  {
   if (vol > 0) vol--;
   set_volume(vol, 0);
   textprintf(screen, font, 150, 230, 7, "VOL: %d ", vol);
  }
			return(bValue);
		case 2:
			bValue=0;
			if(key[KEY_T]) bValue=0x04;
			if(bGame!=1) {
				if(key[KEY_LEFT]) bValue|=0x20;
				if(key[KEY_RIGHT]) bValue|=0x40;
				if(key[KEY_SPACE]) bValue|=0x10;
			}
			return(bValue);
		case 3:
			wValue=(bBitmap<<8)|bBitmapPrevious;
			wValue=wValue<<bShiftValue;
			bValue=(byte)(wValue>>8);
			return(bValue);
		case 4:
			bValue=0x81;
                        if(joysticktester == 1)
			{
                        poll_joystick();
			if (joy_left)  bValue|=0x20; 
			if (joy_right) bValue|=0x40; 
			if (joy_b1) bValue|=0x10;
                        }
			if (key[KEY_ESC]) 
			{
			clear(screen); 
			set_gfx_mode(GFX_TEXT,80,25,0,0); 
			printf("LASER 0.12\nBased On SinVader by Mike Green.\nZ80 Core by Marat Fayzullin\n");			
			exit(0);
			}
			if(key[KEY_1]) bValue|=0x04;
			if(key[KEY_3]) bValue&=~0x01;
			if(key[KEY_RIGHT]) bValue|=0x20;
			if(key[KEY_LEFT]) bValue|=0x40;
			if(key[KEY_SPACE]) bValue|=0x02;
			if(key[KEY_G]) bValue|=0x08;
			if(key[KEY_P])  // Pause
		        {
		        textprintf_centre(screen, font, 128, 108, makecol(255,255,255), "Paused");
		        while(key[KEY_P]);
		        clear_keybuf();
		        while(!keypressed());
		        clear_keybuf();
		        }

  if (key[KEY_PLUS_PAD])
  {
   if (vol < 255) vol++;
   set_volume(vol, 0);
   textprintf(screen, font, 150, 230, 7, "VOL: %d ", vol);
  }

  if (key[KEY_MINUS_PAD])
  {
   if (vol > 0) vol--;
   set_volume(vol, 0);
   textprintf(screen, font, 150, 230, 7, "VOL: %d ", vol);
  }
			return(bValue);
		case 5:
			if(key[KEY_LEFT]) bValue|=0xff;
			return(bValue);
		case 6:
			if(key[KEY_RIGHT]) bValue|=0xff;
			return(bValue);

		default:
			return(0x00);
	}
}
}

void DoOut(byte Port,byte Value)
{

if(lupintester==1)
{ 
	switch(Port) {
		case 2:
			bShiftValue=Value;
			break;
		case 4:
			bBitmapPrevious=bBitmap;
			bBitmap=Value;
			break;
	}
}
else
{
 	static byte bSound1 = 0;
	static byte bSound2 = 0;

	switch(Port) {
		case 2:
			bShiftValue=Value;
			break;
		case 3:
		      if(Value & 0x01 && ~bSound1 & 0x01) play_sample(saucer,vol,128,1000,1);
		      if(~Value& 0x01 &&  bSound1 & 0x01) stop_sample(saucer);
			if(Value & 0x02 && ~bSound1 & 0x02) play_sample(shot,vol,128,1000,0);
			if(Value & 0x04 && ~bSound1 & 0x04) play_sample(basehit,vol,128,1000,0);
			if(~Value & 0x04 && bSound1 & 0x04) stop_sample(basehit);
			if(Value & 0x08 && ~bSound1 & 0x08) play_sample(invaderhit,vol,128,1000,0);
			if(Value & 0x10 && ~bSound1 & 0x10) play_sample(bonus,vol,128,1000,0);
			bSound1=Value;
			break;
		case 4:
			bBitmapPrevious=bBitmap;
			bBitmap=Value;
			break;
		case 5:
            if(christmastester == 1)
		{
			if(Value&0x01 &&  ~bSound2&0x01) play_sample(fleet1,vol,128,1000,0);
			if(Value&0x02 &&  ~bSound2&0x02) play_sample(fleet2,vol,128,1000,0);
			if(Value&0x04 &&  ~bSound2&0x04) play_sample(fleet3,vol,128,1000,0);
			if(Value&0x08 &&  ~bSound2&0x08) play_sample(fleet4,vol,128,1000,0);
			if(Value&0x10 &&  ~bSound2&0x10) play_sample(saucerhit,vol,128,1000,0);
			bSound2=Value;
			break;
		}

		else
		{
			bSound2=Value;
			break;
		}
	}
}
}

void save_state() {
FILE *fd = NULL;
fd = fopen("laser.sav", "wb");
if(!fd) return;
fwrite(&R, sizeof(reg), 1, fd);
fwrite(&RAM[0x2000], 0x2000, 1, fd);
fwrite(&IType, sizeof(IType),1,fd);
fwrite(&IFlag, sizeof(IFlag),1,fd);
fwrite(&IntSync, sizeof(IntSync),1,fd);
fwrite(&IPeriod, sizeof(IPeriod),1,fd);
fwrite(&ICount, sizeof(ICount),1,fd);
fclose(fd);
}

void load_state() {
FILE *fd = NULL;
memset(&R, 0, sizeof(R));
ResetZ80(&R);
fd = fopen("laser.sav", "rb");
if(!fd) return;
fread(&R, sizeof(reg), 1, fd);
fread(&RAM[0x2000], 0x2000, 1, fd);
fread(&IType, sizeof(IType),1,fd);
fread(&IFlag, sizeof(IFlag),1,fd);
fread(&IntSync, sizeof(IntSync),1,fd);
fread(&IPeriod, sizeof(IPeriod),1,fd);
fread(&ICount, sizeof(ICount),1,fd);
fclose(fd);
}

int screen_shot( char *filename )
{
   BITMAP *vis; // visible screen
   int ret;     // return value

   get_palette( invaders );
   vis = create_sub_bitmap( screen, 0, 0, SCREEN_W, SCREEN_H );
   if( vis == NULL )
   {
      ret = save_bitmap( filename, screen, invaders );
   }
   else
   {
      ret = save_bitmap( filename, vis, invaders );
      destroy_bitmap( vis );
   }

   return ret == 0;
}

/**********************************************************/
/*** Emulate BIOS calls. This function is called on the ***/
/*** ED FE instruction to emulate disk/tape access, etc.***/
/*** Replace it with an empty macro for now patching.   ***/
/**********************************************************/
void Patch(reg *R)
{
}

word Interrupt()
  {
  if (IType)
     {
     return (IType == 1 ? 0x0008 : 0x0010);
     }
   return 0xFFFF;
  }
