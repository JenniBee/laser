#ifndef _LASER_H_
#define _LASER_H_


#include <stdio.h>
#include <stdlib.h>
#include "C:\mingw\allegro\include\allegro.h"
#include "cpu.h"
#include "osiline.h"
#include "state.h"
#include "roms.h"
#include "driver.h"
#include "msdos.h"
#include "keyboard.h"
#include "samples.h"
#include "romlist.h"

#define LASER_MAJOR 0
#define LASER_MINOR 20
#define LASER_VERSION "0.20"

byte *RAM;

extern laserDriver *driver;

#endif
