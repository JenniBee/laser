# Laser v0.19
#
#

EXE = laser
SYS = msdos/msdos.o msdos/samples.o
CPUS = cpu/z80/z80.o cpu/m6502/m6502.o
DRIVERS = drivers/8080bw.o
OBJS = $(CPUS) $(DRIVERS) $(SYS) driver.o roms.o state.o

#CFLAGS = -Wall -O3
CFLAGS = -Wall
DEFS = -DLSB_FIRST
LIBS = -L./lib -lalleg
INCS = -I. -I./cpu -I./drivers -I./msdos -I../../mingw/allegro/include
CC = gcc

all: $(EXE).exe

$(EXE).exe: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE).exe $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEFS) $(INCS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(EXE).exe
