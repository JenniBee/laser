/* [sdl/sdl.c] SDL
 *
 */


#include "laser.h"
#include "SDL_framerate.h"

int ldebug = 0;
laserDriver driver;
laserDriver *drvr;
const int FPS = 150;
FPSmanager fps_manager;

int snapshot() {
        int num;
	FILE *snap;
        char fname[32];

        sprintf(fname,"%.4s%04d.bmp","snap",num);
        while(!(snap = fopen(fname, "rb")) == 0) {
                fclose(snap);
                sprintf(fname,"%.4s%04d.bmp","snap",num++);
        }
	if(num > 998) {
		printf("Unable to save %s\r\n",fname);
	} else {
		if(SDL_SaveBMP(screen, fname)) {
			printf("Unable to save %s\r\n",fname);
		}
	}
        return 0;
}

int machine_gfx(int w, int h) {
	screen = SDL_SetVideoMode(w, h, 16, SDL_HWSURFACE);
	if ( screen == NULL ) {
        	fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		exit(1);
	}
	if(ldebug) printf("Debug: SDL_SetVideoMode initialized, %dx%dx16\r\n",w,h);

	SDL_WM_SetCaption("Laser", "laser");
	SDL_ShowCursor(0);

	if(SDL_MUSTLOCK(screen)) {
		SDL_LockSurface(screen);
		if(ldebug) printf("Debug: SDL_LockSurface\r\n");
	}

     SDL_initFramerate( &fps_manager );

     SDL_setFramerate( &fps_manager, FPS ); 

        return(0);
}

int machine_init() {

	return 0;
}

int loadRoms(tagRomList *gameRom) {
        FILE *ap;
        int i;

        /* Load the ROM data into the z80 memory location. */
        for (i=0; i<gameRom->romCount; i++) {
                char *romName=malloc(0x400);
                sprintf(romName,"./roms/%s",gameRom[i].romName);
                if (!(ap = fopen(romName, "rb"))) {
                        printf("Unable to open '%s'.\r\n", gameRom[i].romName);
                        free(romName);
                        return(-1);
                }
                free(romName);
//                fread(RAM + gameRom[i].address, gameRom[i].romSize, 1, ap);
                if (fread(RAM + gameRom[i].address, 1, gameRom[i].romSize, ap) != gameRom[i].romSize) {
                        printf("Error reading from file '%s': %d.\n", gameRom[i].romName, gameRom[i].romSize);
                        return(-1);
                }
                fclose(ap);
		if(ldebug) printf("Debug: '%s' loaded\r\n", gameRom[i].romName);
        }
        return 0;
}

void pal(int index, int r, int g, int b) {
	colour[index] = SDL_MapRGB(screen->format, r, g, b);
	if(ldebug) printf("Debug: i= %d, r=%d, g=%d, b=%d\r\n",index,r,g,b);
}

void usage() {
        printf("\r\n");
	exit_msg();
        printf(" Usage:    laser gamename [options]\r\n");
        printf(" Options:  -keys      : display default key config\r\n");
        printf("\r\n");
}

void exit_msg() {
        printf("Laser v%s\r\n",LASER_VERSION);
        printf("     Based On SinVader by Mike Green.\r\n");
        printf("     Z80 Core by Marat Fayzullin\r\n");
        printf("     6502 Core by Marat Fayzullin and Alex Krasivsky\r\n");
        printf("Current Project Lead:\r\n");
        printf("     MetaFox\r\n");
        printf("Former Co-Project Lead:\r\n");
        printf("     Steven Harris\r\n");
        printf("\r\n");
}

void exit_laser(int code) {
        //free(drvr);

        if(code!=99) {
                exit_msg();
        }
        else if(code!=0 && code!=99) {
                printf("Error code: %d\r\n",code);
        }
	
	SDL_Quit();
	if(ldebug) printf("Debug: SDL_Quit() .. Exiting\r\n");

        exit(code);
}

void pause_laser() {
/*
        BITMAP *pause;

        pause=create_bitmap(SCREEN_W,SCREEN_H);
        blit(screen, pause, 0, 0, 0, 0, driver->s_width, driver->s_height);

        textprintf_centre(screen, font, 128, 108, makecol(255,255,255), "Paused");

        while(key[KEY_P]);
        clear_keybuf();
        while(!keypressed());
        clear_keybuf();

        blit(pause, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        destroy_bitmap(pause);*/
}

void sys_interrupt() {
	keystate = get_keyboard();

	//unlock surface if it was originally locked
	if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);

	//update the screen
	SDL_UpdateRect(screen, 0, 0, 0, 0);

	//must lock the screen before we write directly to it
	if(SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);

        if(keystate[SDLK_p]) {
                pause_laser();
        } else if (keystate[SDLK_ESCAPE]) {
                exit_laser(0);
        }
        /* Todo: Fix these functions
         else if (keystate[SDLK_F12]) {
                snapshot();
                SDL_Delay(300);
        } else if (keystate[SDLK_F5]) {
                driver.save_state();
                SDL_Delay(300);
        } else if (keystate[SDLK_F6]) {
                driver.load_state();
                SDL_Delay(300);
        } */

 SDL_framerateDelay( &fps_manager); // this will delay execution for a while

}

Uint8 *keystate=NULL;
char *get_keyboard(void) {
	SDL_Event event;

	SDL_PollEvent(&event);
	return((char *)SDL_GetKeyState(NULL));
}

int FindOption(char *option, int p, int h, int u, int argc, char **argv) {
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
        int  i;
        char *c;
      
        if (argc > 128)
                argc = 128;

        if (u) {
                for (i = 1; i < argc; i++) {
                        if (!t[i])
                                return i;
                }
                return 0;
        }

        if (p) {
                for (i = 1; i < argc; i++) {                
                        if (strcmp(argv[i], option) == 0) {
                                if (i >= argc)
                                        return 0;
                                t[i + 1] = t[i] = 1;
                                if (!h)
                                        return atoi(argv[i + 1]);
                                else
                                        return strtoul(argv[i + 1], &c, 16);
                        }
                }
                return 0;
        } else {
                for (i = 1; i < argc; i++) {                
                        if (strcmp(argv[i], option) == 0) {
                                t[i] = 1;
                                return i;
                        }
                }                                                          
                return 0;
        }
        return 0;
}

// Code complements of SDL documentation...
void putpixel(SDL_Surface *surface, int x, int y, int c)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    Uint32 pixel = colour[c];

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}


//extern tagGameList *gameList[];


int main(int argc, char *argv[]) {

        if (argc < 2) {
                usage();
                return 1;
        }

        if (FindOption("-keys", 0, 0, 0, argc, argv)) {
                printf("\r\nLaser v%s\r\n",LASER_VERSION);
                printf("\r\n  1               Player 1\r\n");
                printf("  2               Player 2\r\n");
                printf("  3               Insert Coin\r\n");
                printf("  CTRL            Fire\r\n");
                printf("  Up/Down         Up/Down\r\n");
                printf("  Left/Right      Left/Right\r\n");
                printf("  F5              Save State\r\n");
                printf("  F6              Load State\r\n");
                printf("  F12             Save Screenshot\r\n");
                exit(1);
        }

	if((SDL_Init(SDL_INIT_VIDEO)==-1)) { 
		printf("Could not initialize SDL: %s.\n", SDL_GetError());
		exit(-2);
	}
	SDL_EnableUNICODE( 1 );
	if (ldebug) printf("Debug: SDL initialized\r\n");

	drvr = malloc(sizeof( laserDriver));
	if(drvr == NULL) {
		printf("Error: Unable to allocate memory for driver\r\n");
		exit(1);
	}
	drvr = &driver;

        check_roms(argc, argv);

	if(ldebug) printf("Debug: driver.start\r\n");
        driver.start();

	if(ldebug) printf("Debug: driver.shutdown()\r\n");
        driver.shutdown();

        return(0);
}

