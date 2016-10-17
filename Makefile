# Laser
#
#

EXE = laser
SYS = sdl/laser_sdl.o sdl/SDL_framerate.o sdl/samples.o
CPUS = cpu/z80/z80.o cpu/m6502/m6502.o
DRIVERS = drivers/8080bw.o
OBJS = $(SYS) $(CPUS) $(DRIVERS) driver.o roms.o state.o

CFLAGS = -Wall -O3 -g
DEFS = -DLSB_FIRST
LIBS = -L/usr/lib -lSDLmain -lSDL -lm -ldl -lpthread
INCS = -I. -I./cpu -I./drivers -I./sdl -I/usr/include/SDL -D_GNU_SOURCE=1 -Dmain=SDL_main 
#Windows libs and includes
#LIBS = -lmingw32 -lwinmm -L/mingw/lib -lSDLmain -lSDL -mwindows  -lm -luser32 -lgdi32 -lwinmm
#INCS = -I. -I./cpu -I./drivers -I./sdl -I/mingw/include/SDL -D_GNU_SOURCE=1 -Dmain=SDL_main 
CC = gcc
all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(EXE)
