#ifndef _LASER_H_
#define _LASER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "cpu.h"
#include "osiline.h"
#include "state.h"
#include "roms.h"
#include "driver.h"
#include "laser_sdl.h"
#include "samples.h"
#include "romlist.h"

#define LASER_MAJOR 1
#define LASER_MINOR 03
#define LASER_VERSION "1.03"

byte *RAM;

extern laserDriver driver;

extern int ldebug;

#endif
