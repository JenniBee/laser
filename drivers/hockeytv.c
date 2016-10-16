/*
 * Hockey TV Driver
 *
 */

#include "laser.h"
#include "romlist.h"
#include <allegro.h>

#define Paddle_Height 40
#define Goalie_Height 30
#define Barrier_Height 90
#define Barrier_Height2 115

int y3[2] = {100, 100};
int y5[2] = {80, 80};
int Barriery[2] = {0, 0};
int Barriery2[2] = {146, 146};
const int Barrierx[2] = {0, 254};
const int Barrierx2[2] = {0, 254};
const int x5[2] = {100, 146};
const int x3[2] = {10, 231};
int dy3[2] = {0, 0};
int dy5[2] = {0, 0};
int bary[2] = {0, 0};
int bary2[2] = {0, 0};
const int upkey3[2] = {KEY_W, KEY_UP};
const int downkey3[2] = {KEY_S, KEY_DOWN};
int score3[2] = {0, 0};
  int lastwinner3 = 1;
  int lastclock3 = 0;
  int title;

void DrawPaddle3(int p, int c)
{
  rectfill(screen, x3[p], y3[p] + 3, x3[p] + 9, y3[p] + Goalie_Height - 4, c);
}

void DrawPaddle5(int p3, int c3)
{
  rectfill(screen, x5[p3], y5[p3] + 3, x5[p3] + 9, y5[p3] + Paddle_Height - 4, c3);
}

void DrawBarrier(int p4, int c4)
{
  rectfill(screen, Barrierx[p4], Barriery[p4] + 3, Barrierx[p4] + 2, Barriery[p4] + Barrier_Height - 4, c4);
}

void DrawBarrier2(int p5, int c5)
{
  rectfill(screen, Barrierx2[p5], Barriery2[p5] + 3, Barrierx2[p5] + 2, Barriery2[p5] + Barrier_Height2 - 4, c5);
}

void DrawBall3(int x3, int y3, int c)
{
  rectfill(screen, x3, y3 + 6, x3 + 3, y3 + 3, c);
}

byte rdmem_hockeytv(word A) {
        /* Return a location of RAM */
      return 0;
}

void wrmem_hockeytv(word A, byte V) {
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

byte doin_hockeytv(byte Port) {
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

void doout_hockeytv(byte Port, byte Value) {
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

void NMI_hockeytv() {
//        IFlag = 1;
//        IType = (IType == 1 ? 2 : 1);
}

word interrupt_hockeytv() {
//        sys_interrupt();
//        if (IType) {
//                return (IType == 1 ? 0x0008 : 0x0010);
//        }
        return 0;
}

void patch_hockeytv(reg *R) {
        return;
}

int init_hockeytv(tagRomList gameRom[]) {

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

void start_hockeytv() {

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

  while(score3[0] < 10 && score3[1] < 10)
  {
    int balldone, ballx = 0, bally = 0, balldx, balldy3;

    /* setup ball */
    ballx = lastwinner3 ? 40 : 280;
    bally = 100;
    balldx = lastwinner3 ? 3 : -3;
    balldy3 = rand() % 8 - 4;
    if(balldy3 >= 0)
      balldy3 += 4;
    balldone = 0;
    while(!balldone)
    {
      int oldx, oldy3, i, i2, i3, i4;


      while(lastclock3 == retrace_count)
        yield_timeslice();
      lastclock3 = retrace_count;

      /* players */

      for(i = 0; i < 2; i++)
      {
        dy3[i] = dy3[i] * 15/16;

        DrawPaddle3(i, 0);
        y3[i] += dy3[i] / 4;

        if(y3[i] < 0)
        {
          y3[i] = 0;
          dy3[i] = -dy3[i] / 2;
        }
        if(y3[i] > 256 - Paddle_Height)
        {
          y3[i] = 256 - Paddle_Height;
          dy3[i] = -dy3[i] / 2;
        }
        DrawPaddle3(i, i ? 7 : 7);
      }

      /* double players */

      for(i2 = 0; i2 < 2; i2++)
      {
        dy5[i2] = dy5[i2] * 15/16;

        if(key[upkey3[i2]])
          dy5[i2] -= 4;

        if(key[downkey3[i2]])
          dy5[i2] += 4;

        DrawPaddle5(i2, 0);
        y5[i2] += dy5[i2] / 4;

        if(y5[i2] < 0)
        {
          y5[i2] = 0;
          dy5[i2] = -dy5[i2] / 2;
        }
        if(y5[i2] > 256 - Paddle_Height)
        {
          y5[i2] = 256 - Paddle_Height;
          dy5[i2] = -dy3[i2] / 2;
        }
        DrawPaddle5(i2, i2 ? 7 : 7);
      }

      /* Barrier */

      for(i3 = 0; i3 < 2; i3++)
      {
        bary[i3] = bary[i3] * 15/16;

        DrawBarrier(i3, 0);
        Barriery[i3] += bary[i3] / 4;

        if(Barriery[i3] < 0)
        {
          Barriery[i3] = 0;
          bary[i3] = -bary[i3] / 2;
        }
        if(Barriery[i3] > 256 - Barrier_Height)
        {
          Barriery[i3] = 256 - Barrier_Height;
          bary[i3] = -bary[i3] / 2;
        }
        DrawBarrier(i3, i3 ? 7 : 7);
      }

      /* Barrier */

      for(i4 = 0; i4 < 2; i4++)
      {
        bary2[i4] = bary2[i4] * 15/16;

        DrawBarrier2(i4, 0);
        Barriery2[i4] += bary2[i4] / 4;

        if(Barriery2[i4] < 0)
        {
          Barriery2[i4] = 0;
          bary2[i4] = -bary2[i4] / 2;
        }
        if(Barriery2[i4] > 256 - Barrier_Height2)
        {
          Barriery[i4] = 256 - Barrier_Height2;
          bary2[i4] = -bary2[i4] / 2;
        }
        DrawBarrier2(i4, i4 ? 7 : 7);
      }

      /* the ball */

      oldx = ballx;
      oldy3 = bally;

      bally += balldy3;
      if(bally < 5) /* bounce off top */
      {
        bally = 10 - bally;
        balldy3 = -balldy3;
      }
      else if(bally > 254) /* bounce off bottom */
      {
        bally = 508 - bally;
        balldy3 = -balldy3;
      }

      ballx += balldx;

      if(balldx > 0)
      {
        if(ballx > 231 && ballx < 240 && bally >= y3[1] &&
           bally < y3 [1] + Paddle_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - y3[1] - Paddle_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
	  }

	  else
        if(ballx > 146 && ballx < 155 && bally >= y5[1] &&
           bally < y5 [1] + Paddle_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - y3[1] - Paddle_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }


	  else
        if(ballx > 252 && ballx < 256 && bally >= Barriery2[1] &&
           bally < Barriery2 [1] + Barrier_Height2)
        {
          balldx = -balldx;
          balldy3 = (bally - Barriery2[1] - Barrier_Height2 / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }

	  else
        if(ballx > 252 && ballx < 256 && bally <= Barriery[1] &&
           bally < Barriery [1] + Barrier_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - Barriery[1] - Barrier_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }

        else if(ballx >= 256)
        {
          score3[0]++;
          rest(1000);
          lastwinner3 = 0;
          balldone = 1;
        }
      }
      else
      {
        if(ballx < 25 && ballx > 14 && bally >= y3[0] &&
           bally < y3[0] + Paddle_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - y3[0] - Paddle_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }
        else
        if(ballx < 100 && ballx > 92 && bally >= y5[0] &&
           bally < y5[0] + Paddle_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - y3[0] - Paddle_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }

        else
        if(ballx < 2 && ballx && ballx > 0 && bally <= Barriery2[0] &&
           bally < Barriery2[0] + Barrier_Height2)
        {
          balldx = -balldx;
          balldy3 = (bally - Barriery[0] - Barrier_Height2 / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }

        else
        if(ballx < 2 && ballx && ballx > 0 && bally >= Barriery[0] &&
           bally < Barriery[0] + Barrier_Height)
        {
          balldx = -balldx;
          balldy3 = (bally - Barriery[0] - Barrier_Height / 2) / 4;
          if(balldy3 >= 0)
            balldy3++;
        }

        else if(ballx < 1)
        {
          score3[1]++;
          rest(1000);
          lastwinner3 = 1;
          balldone = 1;
        }
      }
      DrawBall3(oldx, oldy3, 0);
      if(!balldone)
        DrawBall3(ballx, bally, 7);

      textprintf(screen, font, 104, 0, 15, "%d  |  %d",
                 score3[0], score3[1]);
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
case KEY_ESC: score3[1] = score3[2] = 11; 
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

void shutdown_hockeytv() {
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
