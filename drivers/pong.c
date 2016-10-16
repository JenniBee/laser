/*
 * Pong Driver
 *
 */

#include "laser.h"
#include "romlist.h"
#include <allegro.h>

#define Paddle_Height 40

int y[2] = {80, 80};
const int x[2] = {0, 246};
int dy[2] = {0, 0};
const int upkey[2] = {KEY_W, KEY_8_PAD};
const int downkey[2] = {KEY_S, KEY_2_PAD};
int score[2] = {0, 0};
  int lastWinner = 1;
  int lastClock = 0;
  int title;

byte rdmem_pong(word A) {
        /* Return a location of RAM */
      return 0;
}

void wrmem_pong(word A, byte V) {
//        int x, y, i, color = 3;

//        if(A < 0x2000) {
//                return;
//        }
//        if(A >= 0x4000 && A < 0x6000) {
//                return;
//        }

//        RAM[A] = V;
//        if (A >= 0x2400 && A < 0x4400) {
//                A -= 0x2400;
//                y = A - ((x = A / 32) * 32);
//                if (x > 23 && y == 24 && x < 104) color = 1;
//                if (x > 23 && y == 21 && x < 104) color = 1;
//                if (x > 119 && y == 24 && x < 200) color = 1;
//                if (x > 119 && y == 21 && x < 200) color = 1;
//                for (i = 0; i < 8; i++) {
//                        putpixel(screen,x,(256-(y * 8 + i)), (V & (1 << i)) ? color : 0);
//                }
//        }

}

// byte bShiftValue = 0;
// byte bBitmap = 0;
// byte bBitmapPrevious = 0;

byte doin_pong(byte Port) {
//	word wValue;
//        int bValue=0x00;

//	switch(Port) {
//		case 0:
//		return(bValue);
//		case 1:
//			bValue=0x81;
//                      if(get_keyboard(SYS_KEY_1)) bValue|=driver->gameSettings.PLAYER_1;//0x04
//                      if(get_keyboard(SYS_KEY_2)) bValue|=driver->gameSettings.PLAYER_2;//0x02
//                      if(get_keyboard(SYS_KEY_3)) bValue&=~driver->gameSettings.INSERT_COIN;
//                      if(get_keyboard(SYS_KEY_LEFT)) bValue|=driver->gameSettings.LEFT;//0x20
//                      if(get_keyboard(SYS_KEY_RIGHT)) bValue|=driver->gameSettings.RIGHT;//0x40
//                      if(get_keyboard(SYS_KEY_SPACE)) bValue|=driver->gameSettings.BUTTON_1;
//			return(bValue);
//		case 2:
//			bValue=0;
//                        if(get_keyboard(SYS_KEY_T)) bValue=driver->gameSettings.EVAL00;//0x04
//			if(bGame!=1) {
//                                if(get_keyboard(SYS_KEY_LEFT)) bValue|=driver->gameSettings.LEFT;
//                                if(get_keyboard(SYS_KEY_RIGHT)) bValue|=driver->gameSettings.RIGHT;
//                                if(get_keyboard(SYS_KEY_SPACE)) bValue|=driver->gameSettings.BUTTON_1;
//			}
//			return(bValue);
//		case 3:
//			wValue=(bBitmap<<8)|bBitmapPrevious;
//			wValue=wValue<<bShiftValue;
//			bValue=(byte)(wValue>>8);
//			return(bValue);
//		case 4:
//			bValue=0x81;
//                        if(get_keyboard(SYS_KEY_1)) bValue|=driver->gameSettings.PLAYER_1;
//                        if(get_keyboard(SYS_KEY_3)) bValue&=~driver->gameSettings.INSERT_COIN;
                        /* left and right seem to be swapped around */
//                        if(get_keyboard(SYS_KEY_RIGHT)) bValue|=driver->gameSettings.LEFT;
//                        if(get_keyboard(SYS_KEY_LEFT)) bValue|=driver->gameSettings.RIGHT;
//                        if(get_keyboard(SYS_KEY_SPACE)) bValue|=driver->gameSettings.BUTTON_1;
//                        if(get_keyboard(SYS_KEY_G)) bValue|=driver->gameSettings.EVAL01;
//			return(bValue);
//		case 5:
//                        if(get_keyboard(SYS_KEY_LEFT)) bValue|=0xFF;
//			return(bValue);
//		case 6:
//                        if(get_keyboard(SYS_KEY_RIGHT)) bValue|=0xFF;
//			return(bValue);
//		default:
//			return(0x00);
//	}
}

void doout_pong(byte Port, byte Value) {
// 	static byte bSound1 = 0;
//	switch(Port) {
//		case 2:
//			bShiftValue=Value;
//			break;
//		case 3:
// 	            if(sound_enable) {
//                        if(Value & 0x01 && ~bSound1 & 0x01) play_sample(saucer,laser_volume,128,1000,1);
//                        if(~Value& 0x01 &&  bSound1 & 0x01) stop_sample(saucer);
//                        if(Value & 0x02 && ~bSound1 & 0x02) play_sample(shot,laser_volume,128,1000,0);
//                      if(Value & 0x04 && ~bSound1 & 0x04) play_sample(basehit,laser_volume,128,1000,0);
//                        if(~Value & 0x04 && bSound1 & 0x04) stop_sample(basehit);
//                        if(Value & 0x08 && ~bSound1 & 0x08) play_sample(invaderhit,laser_volume,128,1000,0);
//                        if(Value & 0x10 && ~bSound1 & 0x10) play_sample(bonus,laser_volume,128,1000,0);
//			}
//			bSound1=Value;
//			break;
//		case 4:
//			bBitmapPrevious=bBitmap;
//			bBitmap=Value;
//			break;
//        }
}

void NMI_pong() {
//        IFlag = 1;
//        IType = (IType == 1 ? 2 : 1);
}

word interrupt_pong() {
//        sys_interrupt();
//        if (IType) {
//                return (IType == 1 ? 0x0008 : 0x0010);
//        }
        return 0;
}

void patch_pong(reg *R) {
        return;
}

int init_pong(tagRomList gameRom[]) {

        /* Allocate RAM */
//      if(!(RAM = malloc (sizeof (char) * 0x10000))) {
//              exit_msg();
//              printf("ERROR: Too low on memory to continue.\r\n");
//              return(1);
//      }

//      if(loadRoms(gameRom)!=0) {
//              free(RAM);
//              return(1);
//      }

//      if(sound_enable) {
//              init_sound();
//              saucer = load_sample("samples/invaders/0.wav");
//              shot = load_sample("samples/invaders/1.wav");
//              basehit = load_sample("samples/invaders/2.wav");
//              invaderhit = load_sample("samples/invaders/3.wav");
//              bonus = load_sample("samples/invaders/9.wav");
//              laser_volume = 255;
//      }

//      pal(1, 255,  0,  0);   /* Red */
//      pal(2,  0, 255,  0);   /* Green */
//      pal(3, 255, 255, 255); /* White */

        /* Reset all Z80 Registers */
//      ResetZ80(&invadersRegs);

        return(0);
}

void start_pong() {

while (!key[KEY_1])
{
      textprintf(screen, font, 104, 0, 15, "0  |  0");
      textprintf(screen, font, 128, 8, 15, "|");
      textprintf(screen, font, 128, 16, 15, "|");
      textprintf(screen, font, 128, 24, 15, "|");
      textprintf(screen, font, 128, 32, 15, "|");
      textprintf(screen, font, 128, 40, 15, "|");
      textprintf(screen, font, 128, 48, 15, "|");
      textprintf(screen, font, 128, 56, 15, "|");
      textprintf(screen, font, 128, 64, 15, "|");
      textprintf(screen, font, 128, 72, 15, "|");
      textprintf(screen, font, 128, 80, 15, "|");
      textprintf(screen, font, 128, 88, 15, "|");
      textprintf(screen, font, 128, 96, 15, "|");
      textprintf(screen, font, 128, 104, 15, "|");
      textprintf(screen, font, 128, 112, 15, "|");
      textprintf(screen, font, 128, 120, 15, "|");
      textprintf(screen, font, 128, 128, 15, "|");
      textprintf(screen, font, 128, 136, 15, "|");
      textprintf(screen, font, 128, 144, 15, "|");
      textprintf(screen, font, 128, 152, 15, "|");
      textprintf(screen, font, 128, 160, 15, "|");
      textprintf(screen, font, 128, 168, 15, "|");
      textprintf(screen, font, 128, 176, 15, "|");
      textprintf(screen, font, 128, 184, 15, "|");
      textprintf(screen, font, 128, 192, 15, "|");
      textprintf(screen, font, 128, 200, 15, "|");
      textprintf(screen, font, 128, 208, 15, "|");
      textprintf(screen, font, 128, 216, 15, "|");
      textprintf(screen, font, 128, 224, 15, "|");
      textprintf(screen, font, 128, 232, 15, "|");
      textprintf(screen, font, 128, 240, 15, "|");
      textprintf(screen, font, 128, 248, 15, "|");
      textprintf(screen, font, 128, 256, 15, "|");
}

  while(score[0] < 10 && score[1] < 10)
  {
    int balldone, ballx = 0, bally = 0, balldx, balldy;

    /* setup ball */
    ballx = lastWinner ? 40 : 280;
    bally = 100;
    balldx = lastWinner ? 3 : -3;
    balldy = rand() % 8 - 4;
    if(balldy >= 0)
      balldy += 4;
    balldone = 0;
    while(!balldone)
    {
      int oldx, oldy, i;


      while(lastClock == retrace_count)
        yield_timeslice();
      lastClock = retrace_count;

      /* players */

      for(i = 0; i < 2; i++)
      {
        dy[i] = dy[i] * 15/16;

        if(key[upkey[i]])
          dy[i] -= 4;

        if(key[downkey[i]])
          dy[i] += 4;

        DrawPaddle(i, 0);
        y[i] += dy[i] / 4;

        if(y[i] < 0)
        {
          y[i] = 0;
          dy[i] = -dy[i] / 2;
        }
        if(y[i] > 256 - Paddle_Height)
        {
          y[i] = 256 - Paddle_Height;
          dy[i] = -dy[i] / 2;
        }
        DrawPaddle(i, i ? 7 : 7);
      }

      /* the ball */

      oldx = ballx;
      oldy = bally;

      bally += balldy;
      if(bally < 5) /* bounce off top */
      {
        bally = 10 - bally;
        balldy = -balldy;
      }
      else if(bally > 254) /* bounce off bottom */
      {
        bally = 508 - bally;
        balldy = -balldy;
      }

      ballx += balldx;

      if(balldx > 0)
      {
        if(ballx > 246 && bally >= y[1] &&
           bally < y[1] + Paddle_Height)
        {
          balldx = -balldx;
          balldy = (bally - y[1] - Paddle_Height / 2) / 4;
          if(balldy >= 0)
            balldy++;
        }
        else if(ballx >= 256)
        {
          score[0]++;
          rest(1000);
          lastWinner = 0;
          balldone = 1;
        }
      }
      else
      {
        if(ballx < 15 && bally >= y[0] &&
           bally < y[0] + Paddle_Height)
        {
          balldx = -balldx;
          balldy = (bally - y[0] - Paddle_Height / 2) / 4;
          if(balldy >= 0)
            balldy++;
        }
        else if(ballx < 1)
        {
          score[1]++;
          rest(1000);
          lastWinner = 1;
          balldone = 1;
        }
      }
      DrawBall(oldx, oldy, 0);
      if(!balldone)
        DrawBall(ballx, bally, 7);

      textprintf(screen, font, 104, 0, 15, "%d  |  %d",
                 score[0], score[1]);
      textprintf(screen, font, 128, 8, 15, "|");
      textprintf(screen, font, 128, 16, 15, "|");
      textprintf(screen, font, 128, 24, 15, "|");
      textprintf(screen, font, 128, 32, 15, "|");
      textprintf(screen, font, 128, 40, 15, "|");
      textprintf(screen, font, 128, 48, 15, "|");
      textprintf(screen, font, 128, 56, 15, "|");
      textprintf(screen, font, 128, 64, 15, "|");
      textprintf(screen, font, 128, 72, 15, "|");
      textprintf(screen, font, 128, 80, 15, "|");
      textprintf(screen, font, 128, 88, 15, "|");
      textprintf(screen, font, 128, 96, 15, "|");
      textprintf(screen, font, 128, 104, 15, "|");
      textprintf(screen, font, 128, 112, 15, "|");
      textprintf(screen, font, 128, 120, 15, "|");
      textprintf(screen, font, 128, 128, 15, "|");
      textprintf(screen, font, 128, 136, 15, "|");
      textprintf(screen, font, 128, 144, 15, "|");
      textprintf(screen, font, 128, 152, 15, "|");
      textprintf(screen, font, 128, 160, 15, "|");
      textprintf(screen, font, 128, 168, 15, "|");
      textprintf(screen, font, 128, 176, 15, "|");
      textprintf(screen, font, 128, 184, 15, "|");
      textprintf(screen, font, 128, 192, 15, "|");
      textprintf(screen, font, 128, 200, 15, "|");
      textprintf(screen, font, 128, 208, 15, "|");
      textprintf(screen, font, 128, 216, 15, "|");
      textprintf(screen, font, 128, 224, 15, "|");
      textprintf(screen, font, 128, 232, 15, "|");
      textprintf(screen, font, 128, 240, 15, "|");
      textprintf(screen, font, 128, 248, 15, "|");
      textprintf(screen, font, 128, 256, 15, "|");

while(keypressed()) 
{ 
switch(readkey() >> 8) 
{ 
case KEY_ESC: score[1] = score[2] = 11; 
balldone = 1; 
break; 
default: break; 
} 
} 
   }

  }

        /* Start Z80 Emulatation */
//        Z80(invadersRegs);
}

void shutdown_pong() {
//        free(RAM);
//        if(sound_enable) {
//                destroy_sample(saucer);
//                destroy_sample(shot);
//                destroy_sample(basehit);
//                destroy_sample(invaderhit);
//                destroy_sample(bonus);
//                shutdown_sound();
//        }
}

void DrawPaddle(int p, int c)
{
  rectfill(screen, x[p], y[p] + 3, x[p] + 9, y[p] + Paddle_Height - 4, c);
}

void DrawBall(int x, int y, int c)
{
  rectfill(screen, x, y + 6, x + 3, y + 3, c);
}