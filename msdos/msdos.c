/* [msdos/msdos.c]
 *
 *    warning:  this file is becoming rather messy,
 *              please feel free to optimise it :)
 *                         - ss_teven
 */


#include "laser.h"
#include <time.h>


PALETTE lpal;

int snapshot() {
        BITMAP *ss;
        int num=0000;
        char fname[32];
        FILE *snap;

        get_palette(lpal);
        ss = create_sub_bitmap(screen, 0, 0, SCREEN_W, SCREEN_H);

        sprintf(fname,"%.4s%04d.bmp","snap",num);
        while(!(snap = fopen(fname, "rb")) == 0) {
                fclose(snap);
                sprintf(fname,"%.4s%04d.bmp","snap",num++);
        }
        save_bitmap(fname, ss, lpal);

        destroy_bitmap(ss);
        return 0;
}

int machine_gfx(int w, int h) {
       set_gfx_mode(GFX_DIRECTX_WIN,w,h,0,0);
        /*if (desktop_color_depth() == 16) {
           set_color_depth(16);
           if (set_gfx_mode(GFX_DIRECTX_OVL,640,480,0,0) != 0) {
              set_color_depth(15);
              if (set_gfx_mode(GFX_DIRECTX_OVL,640,480,0,0) != 0) {
                 allegro_message("Unable to load the DirectX GFX Overlay");
                 return(0);
              }
           }
        }*/
        return(0);
}

int machine_init(void (*proc)(void)) {
        LOCK_FUNCTION((void *)proc);
        return install_int((void *)proc,8);
}

int loadRoms(tagRomList *gameRom) {
        FILE *ap;
        int i;

        /* Load the ROM data into the z80 memory location. */
        for (i=0; i<gameRom->romCount; i++) {
                char *romName=malloc(0x400);
                sprintf(romName,"roms/%s",gameRom[i].romName);
                if (!(ap = fopen(romName, "rb"))) {
                        printf("Unable to open '%s'.\n", gameRom[i].romName);
                        free(romName);
                        return(-1);
                }
                free(romName);
                fread(RAM + gameRom[i].address, gameRom[i].romSize, 1, ap);
/*                if (fread(RAM + gameRom[i].address, gameRom[i].romSize, 1, ap) != gameRom[i].romSize) {
                        printf("Error reading from file '%s'.\n", gameRom[i].romName);
                        return(-1);
                }*/
                fclose(ap);
        }
        return 0;
}

void pal(int index, char r, char g, char b) {
        PALETTE lcol;

        lcol[0].r = r;
        lcol[0].g = g;
        lcol[0].b = b;
        //vsync();
        set_color(index,lcol);
        //outp(0x3c8,index);
        //outp(0x3c9,r);
        //outp(0x3c9,g);
        //outp(0x3c9,b);
}

void usage() {
        printf("\r\n");
        printf("Laser v%s Win32\r\n",LASER_VERSION);
        printf("     Based on SinVader by Mike Green\r\n");
        printf("     Z80 Core by Marat Fayzullin\r\n");
        printf("     6502 Core by Marat Fayzullin and Alex Krasivsky\r\n");
        printf("     Current authors:\r\n");
        printf("        MetaFox  -  ss_teven\r\n");
        printf("\r\n");
        printf(" Usage:    laser gamename [options]\r\n");
        printf(" Options:  -sound     : enable sound\r\n");
        printf("           -keys      : display default key config\r\n");
        printf("\r\n");
}

void exit_msg() {
        if(msdos_set==1) {
                clear(screen);
                set_gfx_mode(GFX_TEXT,80,25,0,0);
                allegro_exit();
                msdos_set=0;
        }
        printf("Laser v%s Win32\r\n",LASER_VERSION);
        printf("  Based On SinVader by Mike Green.\r\n");
        printf("  Z80 Core by Marat Fayzullin\r\n");
        printf("  6502 Core by Marat Fayzullin and Alex Krasivsky\r\n");
        printf("\r\n");
}

void exit_laser(int code) {
        free(driver);

        if(code!=99) {
                exit_msg();
        }
        else if(code!=0 && code!=99) {
                printf("Error code: %d\r\n",code);
        }
        exit(code);
}

void pause_laser() {
        BITMAP *pause;

        pause=create_bitmap(SCREEN_W,SCREEN_H);
        blit(screen, pause, 0, 0, 0, 0, driver->s_width, driver->s_height);

        textprintf_centre(screen, font, 128, 108, makecol(255,255,255), "Paused");

        while(key[KEY_P]);
        clear_keybuf();
        while(!keypressed());
        clear_keybuf();

        blit(pause, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        destroy_bitmap(pause);
}

void sys_interrupt() {

        if(get_keyboard(SYS_KEY_P)) {
                pause_laser();
        } else if (get_keyboard(SYS_KEY_ESC)) {
                exit_laser(0);
        } else if (get_keyboard(KEY_F12)) {
                snapshot();
                //Sleep(100);
        } else if (get_keyboard(KEY_F5)) {
                driver->save_state();
                //Sleep(1);
        } else if (get_keyboard(KEY_F6)) {
                driver->load_state();
                //Sleep(1);
        }
}

int get_keyboard(int sc) {
        return key[sc];
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


laserDriver *driver;

extern tagGameList *gameList[];


int main(int argc, char *argv[]) {
        char *title;

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

        allegro_init();
        install_timer();
        install_keyboard();

        machine_gfx(256, 256);

        /* z80 specifics must change later  */
        LOCK_VARIABLE (IType);
        LOCK_VARIABLE (IFlag);

        title=malloc(256);
        sprintf(title,"%s%s","Laser v",LASER_VERSION);
        set_window_title(title);
        set_window_close_button(0);
        free(title);

        msdos_set=1;

        driver = malloc(sizeof(laserDriver));
        check_roms(argc, argv);

        driver->start();
        driver->shutdown();

        return(0);
}

END_OF_MAIN();
