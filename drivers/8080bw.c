/*
 * Midway 8080 b/w Driver
 *
 *
 *       Memory map
 *              0000 - 1FFF (main program rom)
 *              2000 - 23FF (ram)
 *              2400 - 3FFF (vram)
 *              3FFF - FFFF (not used?)
 *
 */

#include "laser.h"
#include "romlist.h"

/* samples */
/*wave *saucer;
wave *shot;
wave *basehit;
wave *invaderhit;
wave *bonus;*/
wave *samples[4];

/* registers/interrupts */
//volatile
extern byte IType;
extern byte IFlag;
extern int  ICount;
extern int  IPeriod;
extern byte IntSync;
reg invadersRegs;
byte bGame;

void NMI_invaders() {
        IFlag = 1;
        IType = (IType == 1 ? 2 : 1);
	sys_interrupt();
}

byte rdmem_invaders(word A) {
        /* Return a location of RAM */
        return RAM[A];
}

void wrmem_lupin3(word A, byte V) {
        int x, y, i, color = 3;

        if(A < 0x2000) {
                return;
        }
        if(A >= 0x4000 && A < 0x6000) {
                return;
        }

        RAM[A] = V;
        if (A >= 0x2400 && A < 0x4400) {
                A -= 0x2400;
                y = A - ((x = A / 32) * 32);
                if (x > 23 && y == 24 && x < 104) color = 1;
                if (x > 23 && y == 21 && x < 104) color = 1;
                if (x > 119 && y == 24 && x < 200) color = 1;
                if (x > 119 && y == 21 && x < 200) color = 1;
                for (i = 0; i < 8; i++) {
                        putpixel(screen,x,(256-(y * 8 + i)), (V & (1 << i)) ? color : 0);
                }
        }

}
void wrmem_horizontal(word A, byte V) {
        int x, y, i, color = 3;

        if(A < 0x2000) {
                return;
	}

        RAM[A] = V;
	  
        if (A >= 0x2400 && A < 0x4400) {
                A -= 0x2400;
                y = A - ((x = A / 32) * 32);
                if (y < 8) color = 3;
                if (y >  23 && y < 28) color = 3;
                if (x <  16 && y <  2) color = 3;
                if (x > 135 && y <  2) color = 3;
                for (i = 0; i < 8; i++) {
                        putpixel(screen, (y * 8 + i), x, (V & (1 << i)) ? color : 0);
                }
        }

}
void wrmem_invadpt2(word A, byte V) {
        int x, y, i, color = 3;

        if(A < 0x2000) {
                return;
	}

        RAM[A] = V;
	  
        if (A >= 0x2400 && A < 0x4400) {
                A -= 0x2400;
                y = A - ((x = A / 32) * 32);
                if (x > 135 && y > 28) color = 14;
                if (x > 61 && x < 150 && y > 28) color = 1;
                if (x > 61 && x < 134 && y > 27 && y < 29) color = 2;
                if (x < 60 && y > 28) color = 11;
                if (y < 24) color = 2;
                if (y < 20) color = 11;
                if (y < 16) color = 5;
                if (y < 12) color = 14;
                if (y < 8) color = 1;
                if (y < 5) color = 11;
                if (y < 4) color = 1;
                if (y >  23 && y < 28) color = 1;
                if (x <  100 && y <  2) color = 11;
                if (x > 135 && x < 182 && y <  2) color = 5;
                if (x > 135 && x > 182 && y <  2) color = 11;
                for (i = 0; i < 8; i++) {
                        putpixel(screen,x,(256-(y * 8 + i)), (V & (1 << i)) ? color : 0);
                }
        }

}
void wrmem_invaders(word A, byte V) {
        int x, y, i, color = 3;

        if(A < 0x2000) {
                return;
	}

        RAM[A] = V;

        if (A >= 0x2400 && A < 0x4400) {
                A -= 0x2400;
                y = A - ((x = A / 32) * 32);
                if (y < 8)            color = 2;
                if (y >  23 && y < 28) color = 1;
                if (x <  16 && y <  2) color = 3;
                if (x > 135 && y <  2) color = 3;
                for (i = 0; i < 8; i++) {
                        putpixel(screen,x,(256-(y * 8 + i)), (V & (1 << i)) ? color : 0);
                }
        }

}

byte bShiftValue = 0;
byte bBitmap = 0;
byte bBitmapPrevious = 0;

byte doin_invaders(byte Port) {
	word wValue;
        int bValue=0x00;
	keystate = get_keyboard();

	switch(Port) {
		case 0:
			return(bValue);
		case 1:
			bValue=0x81;
                        if(keystate[SDLK_1]) bValue|=driver.gameSettings.PLAYER_1;//0x04
                        if(keystate[SDLK_2]) bValue|=driver.gameSettings.PLAYER_2;//0x02
                        if(keystate[SDLK_3]) bValue&=~driver.gameSettings.INSERT_COIN;
                        if(keystate[SDLK_LEFT]) bValue|=driver.gameSettings.LEFT;//0x20
                        if(keystate[SDLK_RIGHT]) bValue|=driver.gameSettings.RIGHT;//0x40
                        if(keystate[SDLK_SPACE]) bValue|=driver.gameSettings.BUTTON_1;
			return(bValue);
		case 2:
			bValue=0;
                        if(keystate[SDLK_t]) bValue=driver.gameSettings.EVAL00;//0x04
			if(bGame!=1) {
                                if(keystate[SDLK_LEFT]) bValue|=driver.gameSettings.LEFT;
                                if(keystate[SDLK_RIGHT]) bValue|=driver.gameSettings.RIGHT;
                                if(keystate[SDLK_SPACE]) bValue|=driver.gameSettings.BUTTON_1;
			}
			return(bValue);
		case 3:
			wValue=(bBitmap<<8)|bBitmapPrevious;
			wValue=wValue<<bShiftValue;
			bValue=(byte)(wValue>>8);
			return(bValue);
		case 4:
			bValue=0x81;
                        if(keystate[SDLK_1]) bValue|=driver.gameSettings.PLAYER_1;
                        if(keystate[SDLK_3]) bValue&=~driver.gameSettings.INSERT_COIN;
                        /* left and right seem to be swapped around */
                        if(keystate[SDLK_RIGHT]) bValue|=driver.gameSettings.LEFT;
                        if(keystate[SDLK_LEFT]) bValue|=driver.gameSettings.RIGHT;
			if(keystate[SDLK_SPACE]) bValue|=driver.gameSettings.BUTTON_1;
                        if(keystate[SDLK_g]) bValue|=driver.gameSettings.EVAL01;
			return(bValue);
		case 5:
                        if(keystate[SDLK_LEFT]) bValue|=0xFF;
			return(bValue);
		case 6:
                        if(keystate[SDLK_RIGHT]) bValue|=0xFF;
			return(bValue);
		default:
			return(0x00);
	} 
}

void doout_invaders(byte Port, byte Value) {
 	static byte bSound1 = 0;
	static byte bSound2 = 0;
	switch(Port) {
		case 2:
			bShiftValue=Value;
			break;
		case 3:
 	            if(sound_enable) {
                        if(Value & 0x01 && ~bSound1 & 0x01) play_wav(samples[0], 0, 1);
                        if(~Value& 0x01 &&  bSound1 & 0x01) stop_wav(0);
                        if(Value & 0x02 && ~bSound1 & 0x02) play_wav(samples[1], 1, 0);
                        if(Value & 0x04 && ~bSound1 & 0x04) play_wav(samples[2], 2, 0);
                        if(~Value & 0x04 && bSound1 & 0x04) stop_wav(2);
                        if(Value & 0x08 && ~bSound1 & 0x08) play_wav(samples[3], 3, 0);
                        if(Value & 0x10 && ~bSound1 & 0x10) play_wav(samples[4], 4, 0);

			}
			bSound1=Value;
			break;
		case 4:
			bBitmapPrevious=bBitmap;
			bBitmap=Value;
			break;
		case 5:
 	            if(sound_enable) {
play_wav(samples[0], 0, 1);
                        if(Value & 0x04 && ~bSound1 & 0x04) play_wav(samples[5], 5, 0);
                        if(Value & 0x04 && ~bSound1 & 0x04) play_wav(samples[6], 6, 0);
                        if(Value & 0x08 && ~bSound1 & 0x08) play_wav(samples[7], 7, 0);
                        if(Value & 0x10 && ~bSound1 & 0x10) play_wav(samples[8], 8, 0);
                }
        }
}

word interrupt_polaris() {
/*        static int cloud_speed;

        cloud_speed++;

        if (cloud_speed >= 8) {
		cloud_speed = 0;

		polaris_cloud_pos--;

                if (polaris_cloud_pos >= 0xE0) {
                        polaris_cloud_pos = 0xDF;
		}
        }*/
        return(interrupt_invaders());
}

word interrupt_invaders() {
        if (IType) {
                return (IType == 1 ? 0x0008 : 0x0010);
        }
        return 0xFFFF;
}

void patch_invaders(reg *R) {
        return;
}

int init_invaders(tagRomList gameRom[]) {

        /* Allocate RAM */
        if(!(RAM = malloc (sizeof (char) * 0x10000))) {
                exit_msg();
                printf("ERROR: Too low on memory to continue.\r\n");
                return(1);
        }


        if(loadRoms(gameRom)!=0) {
                free(RAM);
                return(1);
        }

        if(sound_enable) {
		if(init_sound() == 0) {
			samples[0] =        load_wav("./samples/invaders/0.wav");
			samples[1] =          load_wav("./samples/invaders/1.wav");
			samples[2] =       load_wav("./samples/invaders/2.wav");
			samples[3] =    load_wav("./samples/invaders/3.wav");
			samples[4] =         load_wav("./samples/invaders/9.wav");
			samples[5] =         load_wav("./samples/invaders/4.wav");
			samples[6] =         load_wav("./samples/invaders/5.wav");
			samples[7] =         load_wav("./samples/invaders/6.wav");
			samples[8] =         load_wav("./samples/invaders/7.wav");
			//samples[0] = malloc(sizeof(wave));samples[0]=NULL;
			laser_volume = 255; //not used anymore
		}
        }

	pal(0, 0x00, 0x00, 0x00);  /* Black */
        pal(1, 0xFF, 0x00, 0x00);  /* Red */
        pal(2, 0x00, 0xFF, 0x00);  /* Green */
        pal(3, 0xFF, 0xFF, 0xFF);  /* White */

        /* Reset all Z80 Registers */
	if(ldebug) printf("Debug: Resetting Z80 registers...\r\n");
	
        ResetZ80(&invadersRegs);
	if(ldebug) printf("Debug: ...done\r\n");

        return(0);
}

void start_invaders() {
        /* Start Z80 Emulatation */
	if(ldebug) printf("Debug: Starting emulation...\r\n");
        Z80(invadersRegs);
}

void shutdown_invaders() {
        free(RAM);
        if(sound_enable) {
                unload_wav(samples[0]);
                unload_wav(samples[1]);
                unload_wav(samples[2]);
                unload_wav(samples[3]);
                unload_wav(samples[4]);
                shutdown_sound();
        }
}
/*fwrite(&IType, sizeof(IType),1,fd);
fwrite(&IFlag, sizeof(IFlag),1,fd);
fwrite(&IntSync, sizeof(IntSync),1,fd);
fwrite(&IPeriod, sizeof(IPeriod),1,fd);
fwrite(&ICount, sizeof(ICount),1,fd);
*/

void save_state_invaders() {
        state *invadstate;
        invadstate->stateRAM = malloc(0x2000);

        memcpy(invadstate->stateRAM,&RAM[0x2000],0x2000);
        //memcpy(&invadstate->z80R,&invadersRegs,sizeof(reg));
        invadstate->z80R = invadersRegs;
        save_state(invadstate, 0x2000);

        free(invadstate->stateRAM);
}

void load_state_invaders() {
        state *invadstate;

        invadstate->stateRAM = malloc(0x2000);
        invadstate = load_state(0x2000);

        memset(&invadersRegs, 0, sizeof(reg));
        ResetZ80(&invadersRegs);
        memcpy(&RAM[0x2000],invadstate->stateRAM,0x2000);
        //memcpy(&invadersRegs,&invadstate->z80R,sizeof(reg));
        invadersRegs = invadstate->z80R;

        free(invadstate->stateRAM);
}

