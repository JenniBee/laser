#include "laser.h"

tagRomList alieninvRom[] = {
  {"alieninv/alieninv.h",      0x0000, 0x0800, 4 },
  {"alieninv/alieninv.g",      0x0800, 0x0800, 0 },
  {"alieninv/alieninv.f",      0x1000, 0x0800, 0 },
  {"alieninv/alieninv.e",      0x1800, 0x0800, 0 },
};

tagRomList ballbombRom[] = {
  {"ballbomb/tn01",      0x0000, 0x0800, 7 },
  {"ballbomb/tn02",      0x0800, 0x0800, 0 },
  {"ballbomb/tn03",      0x1000, 0x0800, 0 },
  {"ballbomb/tn04",      0x1800, 0x0800, 0 },
  {"ballbomb/tn05-1",      0x4000, 0x0800, 0 },
  {"ballbomb/tn06",      0x5000, 0x0400, 0 },
  {"ballbomb/tn07",      0x5400, 0x0400, 0 }
};

tagRomList cosmicmoRom[] = {
  {"cosmicmo/cosmicmo.1",      0x0000, 0x0400, 7 },
  {"cosmicmo/cosmicmo.2",      0x0400, 0x0400, 0 },
  {"cosmicmo/cosmicmo.3",      0x0800, 0x0400, 0 },
  {"cosmicmo/cosmicmo.4",      0x0c00, 0x0400, 0 },
  {"cosmicmo/cosmicmo.5",      0x4000, 0x0400, 0 },
  {"cosmicmo/cosmicmo.6",      0x4400, 0x0400, 0 },
  {"cosmicmo/cosmicmo.7",      0x4800, 0x0400, 0 },
};

tagRomList cosmicm2Rom[] = {
  {"cosmicm2/3907.bin",      0x0000, 0x0400, 7 },
  {"cosmicmo/cosmicmo.2",      0x0400, 0x0400, 0 },
  {"cosmicmo/cosmicmo.3",      0x0800, 0x0400, 0 },
  {"cosmicmo/cosmicmo.4",      0x0c00, 0x0400, 0 },
  {"cosmicm2/3906.bin",      0x4000, 0x0400, 0 },
  {"cosmicmo/cosmicmo.6",      0x4400, 0x0400, 0 },
  {"cosmicmo/cosmicmo.7",      0x4800, 0x0400, 0 }
};

tagRomList galxwarstRom[] = {
  {"galxwarst/galxwars.0",       0x0000, 0x0400, 6 },
  {"galxwarst/galxwars.1",       0x0400, 0x0400, 0 },
  {"galxwarst/galxwars.2",       0x0800, 0x0400, 0 },
  {"galxwarst/galxwars.3",       0x0c00, 0x0400, 0 },
  {"galxwarst/galxwars.4",       0x4000, 0x0400, 0 },
  {"galxwarst/galxwars.5",       0x4400, 0x0400, 0 }
};

tagRomList indianbtRom[] = {
  {"indianbt/1.36",     0x0000, 0x0800, 8 },
  {"indianbt/2.35",     0x0800, 0x0800, 0 },
  {"indianbt/3.34",     0x1000, 0x0800, 0 },
  {"indianbt/4.33",     0x1800, 0x0800, 0 },
  {"indianbt/5.32",     0x4000, 0x0800, 0 },
  {"indianbt/6.31",     0x4800, 0x0800, 0 },
  {"indianbt/7.42",     0x5000, 0x0800, 0 },
  {"indianbt/8.41",     0x5800, 0x0800, 0 }
};

tagRomList invrvngeRom[] = {
  {"invrvnge/invrvnge.h",       0x0000, 0x0800, 4 },
  {"invrvnge/invrvnge.g",       0x0800, 0x0800, 0 },
  {"invrvnge/invrvnge.f",       0x1000, 0x0800, 0 },
  {"invrvnge/invrvnge.e",       0x1800, 0x0800, 0 }
};

tagRomList invrvngeaRom[] = {
  {"invrvngea/5m.bin",       0x0000, 0x0800, 4 },
  {"invrvngea/5n.bin",       0x0800, 0x0800, 0 },
  {"invrvngea/5p.bin",       0x1000, 0x0800, 0 },
  {"invrvngea/5r.bin",       0x1800, 0x0800, 0 }
};

tagRomList laserRom[] = {
  {"laser/1.u36",       0x0000, 0x0800, 4 },
  {"laser/2.u35",       0x0800, 0x0800, 0 },
  {"laser/3.u34",       0x1000, 0x0800, 0 },
  {"laser/4.u33",       0x1800, 0x0800, 0 }
};

tagRomList lrescueRom[] = {
  {"lrescue/lrescue.1", 0x0000, 0x0800, 6 },
  {"lrescue/lrescue.2", 0x0800, 0x0800, 0 },
  {"lrescue/lrescue.3", 0x1000, 0x0800, 0 },
  {"lrescue/lrescue.4", 0x1800, 0x0800, 0 },
  {"lrescue/lrescue.5", 0x4000, 0x0800, 0 },
  {"lrescue/lrescue.6", 0x4800, 0x0800, 0 }
};

tagRomList ozmawarsRom[] = {
  {"ozmawars/mw01",      0x0000, 0x0800, 6 },
  {"ozmawars/mw02",      0x0800, 0x0800, 0 },
  {"ozmawars/mw03",      0x1000, 0x0800, 0 },
  {"ozmawars/mw04",      0x1800, 0x0800, 0 },
  {"ozmawars/mw05",      0x4000, 0x0800, 0 },
  {"ozmawars/mw06",      0x4800, 0x0800, 0 },
};

tagRomList ozmawars2Rom[] = {
  {"ozmawars/mw01",     0x0000, 0x0800, 9 },
  {"ozmawars/mw02",     0x0800, 0x0800, 0 },
  {"ozmawars2/oz5",      0x1000, 0x0400, 0 },
  {"ozmawars2/oz6",      0x1400, 0x0400, 0 },
  {"ozmawars2/oz7",      0x1800, 0x0400, 0 },
  {"ozmawars2/oz8",      0x1c00, 0x0400, 0 },
  {"ozmawars/mw05",     0x4000, 0x0800, 0 },
  {"ozmawars2/oz11",     0x4800, 0x0400, 0 },
  {"ozmawars2/oz12",     0x4c00, 0x0400, 0 },
};

tagRomList spaceattRom[] = {
  {"spaceatt/h",          0x0000, 0x0400, 6 },
  {"spaceatt/sv02.bin",   0x0400, 0x0400, 0 },
  {"spaceatt/f",          0x0800, 0x0400, 0 },
  {"spaceatt/c",          0x1400, 0x0400, 0 },
  {"spaceatt/b",          0x1800, 0x0400, 0 },
  {"spaceatt/a",          0x1C00, 0x0400, 0 }
};

tagRomList spaceat2Rom[] = {
  {"spaceat2/spaceatt.h", 0x0000, 0x0800, 4 },
  {"spaceat2/spaceatt.g", 0x0800, 0x0800, 0 },
  {"spaceat2/spaceatt.f", 0x1000, 0x0800, 0 },
  {"spaceat2/spaceatt.e", 0x1800, 0x0800, 0 }
};

tagRomList invadersRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 4 },
  {"invaders/invaders.g",       0x0800, 0x0800, 0 },
  {"invaders/invaders.f",       0x1000, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};

tagRomList sicvRom[] = {
  {"sicv/Cv17.36",    0x0000, 0x0800, 6 },
  {"sicv/Cv18.35",    0x0800, 0x0800, 0 },
  {"sicv/Cv19.34",    0x1000, 0x0800, 0 },
  {"sicv/Cv20.33",    0x1800, 0x0800, 0 },
  {"sicv/cv01.1",  0x2000, 0x0400, 0 },
  {"sicv/cv02.2",  0x2400, 0x0400, 0 }
};

tagRomList sisvRom[] = {
  {"sisv/sv01.36",          0x0000, 0x0400, 6 },
  {"sisv/sv02.35",          0x0400, 0x0400, 0 },
  {"sisv/sv10.34",          0x0800, 0x0400, 0 },
  {"sisv/sv04.31",          0x1400, 0x0400, 0 },
  {"sisv/sv09.42",          0x1800, 0x0400, 0 },
  {"sisv/sv06.41",          0x1C00, 0x0400, 0 }
};

tagRomList sisv2Rom[] = {
  {"sisv2/sv01.36",          0x0000, 0x0400, 6 },
  {"sisv2/sv11.35",          0x0400, 0x0400, 0 },
  {"sisv2/sv12.34",          0x0800, 0x0400, 0 },
  {"sisv2/sv04.31",          0x1400, 0x0400, 0 },
  {"sisv2/sv13.42",          0x1800, 0x0400, 0 },
  {"sisv2/sv14.41",          0x1C00, 0x0400, 0 }
};

tagRomList sitvRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 5 },
  {"sitv/tv02.rp1",             0x0800, 0x0800, 0 },
  {"sitv/tv03.n1",              0x1000, 0x0800, 0 },
  {"sitv/tv04.m1",              0x1800, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};

tagRomList invaddlxRom[] = {
  {"invaddlx/invdelux.h",       0x0000, 0x0800, 5 },
  {"invaddlx/invdelux.g",       0x0800, 0x0800, 0 },
  {"invaddlx/invdelux.f",       0x1000, 0x0800, 0 },
  {"invaddlx/invdelux.e",       0x1800, 0x0800, 0 },
  {"invaddlx/invdelux.d",       0x4000, 0x0800, 0 }
};

tagRomList invadpt2Rom[] = {
  {"invadpt2/pv01",       0x0000, 0x0800, 7 },
  {"invadpt2/pv02",       0x0800, 0x0800, 0 },
  {"invadpt2/pv03",       0x1000, 0x0800, 0 },
  {"invadpt2/pv04",       0x1800, 0x0800, 0 },
  {"invadpt2/pv05",       0x4000, 0x0400, 0 },
  {"invaddlx/invdelux.e", 0x1800, 0x0800, 0 },
  {"invaddlx/invdelux.d", 0x4000, 0x0800, 0 }
};

tagRomList invader4Rom[] = {
  {"invader4/spin4.a",       0x0000, 0x0800, 4 },
  {"invader4/spin4.b",       0x0800, 0x0800, 0 },
  {"invader4/spin4.c",       0x1000, 0x0800, 0 },
  {"invader4/spin4.d",       0x1800, 0x0800, 0 }
};

tagRomList jspecterRom[] = {
  {"jspecter/3305.u6",       0x0000, 0x1000, 2 },
  {"jspecter/3306.u7",       0x1400, 0x1000, 0 }
};

tagRomList jspecter2Rom[] = {
  {"jspecter2/unksi.b2",       0x0000, 0x1000, 2 },
  {"jspecter2/unksi.a2",       0x1400, 0x1000, 0 }
};

tagRomList solfightRom[] = {
  {"solfight/solfight.m",      0x0000, 0x0800, 6 },
  {"solfight/solfight.n",      0x0800, 0x0800, 0 },
  {"solfight/solfight.p",      0x1000, 0x0800, 0 },
  {"solfight/solfight.r",      0x1800, 0x0800, 0 },
  {"ozmawars/mw05",      0x4000, 0x0800, 0 },
  {"solfight/solfight.t",      0x4800, 0x0800, 0 }
};

tagRomList spcekingRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 4 },
  {"spceking/spcekng2",       0x0800, 0x0800, 0 },
  {"spceking/spcekng3",       0x1000, 0x0800, 0 },
  {"spceking/spcekng4",       0x1800, 0x0800, 0 }
};

tagRomList spclaserRom[] = {
  {"spclaser/la01",       0x0000, 0x0800, 4 },
  {"spclaser/spcewarl.2", 0x0800, 0x0800, 0 },
  {"spclaser/la03",       0x1000, 0x0800, 0 },
  {"spclaser/la04",       0x1800, 0x0800, 0 }
};

tagRomList spacephRom[] = {
  {"spaceph/sv01.bin",      0x0000, 0x0400, 12 },
  {"spaceph/sv02.bin",      0x0400, 0x0400, 0 },
  {"spaceph/sv03.bin",      0x0800, 0x0400, 0 },
  {"spaceph/sv04.bin",      0x0c00, 0x0400, 0 },
  {"spaceph/sv05.bin",      0x1000, 0x0400, 0 },
  {"spaceph/sv06.bin",      0x1400, 0x0400, 0 },
  {"spaceph/sv07.bin",      0x1800, 0x0400, 0 },
  {"spaceph/sv08.bin",      0x1c00, 0x0400, 0 },
  {"spaceph/sv09.bin",      0x4000, 0x0400, 0 },
  {"spaceph/sv10.bin",      0x4400, 0x0400, 0 },
  {"spaceph/sv11.bin",      0x4800, 0x0400, 0 },
  {"spaceph/sv12.bin",      0x4c00, 0x0400, 0 }
};

tagRomList spacewr3Rom[] = {
  {"spacewr3/ic36.bin",       0x0000, 0x0800, 5 },
  {"spacewr3/ic35.bin",       0x0800, 0x0800, 0 },
  {"spacewr3/ic34.bin",       0x1000, 0x0800, 0 },
  {"spacewr3/ic33.bin",       0x1800, 0x0800, 0 },
  {"spacewr3/ic32.bin",       0x4000, 0x0400, 0 }
};

tagRomList starwRom[] = {
  {"starw/roma",      0x0000, 0x0400, 6 },
  {"starw/romb",      0x0400, 0x0400, 0 },
  {"starw/romc",      0x0800, 0x0400, 0 },
  {"starw/romd",      0x1400, 0x0400, 0 },
  {"starw/rome",      0x1800, 0x0400, 0 },
  {"starw/romf",      0x1c00, 0x0400, 0 },
};

tagRomList sinvemagRom[] = {
  {"sinvemag/sv01.36",    0x0000, 0x0400, 6 },
  {"sinvemag/emag_si.b",   0x0400, 0x0400, 0 },
  {"sinvemag/emag_si.c",   0x0800, 0x0400, 0 },
  {"sinvemag/emag_si.d",   0x1400, 0x0400, 0 },
  {"sinvemag/emag_si.e",   0x1800, 0x0400, 0 },
  {"sinvemag/emag_si.f",   0x1c00, 0x0400, 0 },
};

tagRomList sinvzenRom[] = {
  {"sinvzen/1.bin",     0x0000, 0x0400, 8 },
  {"sinvzen/2.bin",     0x0400, 0x0400, 0 },
  {"sinvzen/3.bin",     0x0800, 0x0400, 0 },
  {"sinvzen/4.bin",     0x0c00, 0x0400, 0 },
  {"sinvzen/5.bin",     0x1000, 0x0400, 0 },
  {"sinvzen/6.bin",     0x1400, 0x0400, 0 },
  {"sinvzen/7.bin",     0x1800, 0x0400, 0 },
  {"sinvzen/8.bin",     0x1c00, 0x0400, 0 }
};

tagRomList ultrainvRom[] = {
  {"ultrainv/in-01.bin",          0x0000, 0x0400, 6 },
  {"ultrainv/in-02.bin",          0x0400, 0x0400, 0 },
  {"ultrainv/in-03.bin",          0x0800, 0x0400, 0 },
  {"ultrainv/in-04.bin",          0x1400, 0x0400, 0 },
  {"ultrainv/in-05.bin",          0x1800, 0x0400, 0 },
  {"ultrainv/in-06.bin",          0x1C00, 0x0400, 0 }
};

tagRomList yosakdonRom[] = {
  {"yosakdon/yd1.bin",  0x0000, 0x0400, 7 },
  {"yosakdon/yd2.bin",  0x0400, 0x0400, 0 },
  {"yosakdon/yd3.bin",  0x0800, 0x0400, 0 },
  {"yosakdon/yd4.bin",  0x0c00, 0x0400, 0 },
  {"yosakdon/yd5.bin",  0x1400, 0x0400, 0 },
  {"yosakdon/yd6.bin",  0x1800, 0x0400, 0 },
  {"yosakdon/yd7.bin",  0x1c00, 0x0400, 0 }
};

tagRomList yosakdonaRom[] = {
  {"yosakdona/yosaku1",  0x0000, 0x0400, 7 },
  {"yosakdon/yd2.bin",  0x0400, 0x0400, 0 },
  {"yosakdona/yosaku3",  0x0800, 0x0400, 0 },
  {"yosakdona/yosaku4",  0x0c00, 0x0400, 0 },
  {"yosakdona/yosaku5",  0x1400, 0x0400, 0 },
  {"yosakdona/yosaku6",  0x1800, 0x0400, 0 },
  {"yosakdona/yosaku7",  0x1c00, 0x0400, 0 }
};

/* TODO: Fix these ROM sets

tagRomList lupin3Rom[] = {
  {"lupin3/lp12.bin",      0x0000, 0x0800, 7 },
  {"lupin3/lp13.bin",      0x0800, 0x0800, 0 },
  {"lupin3/lp14.bin",      0x1000, 0x0800, 0 },
  {"lupin3/lp15.bin",      0x1800, 0x0800, 0 },
  {"lupin3/lp16.bin",      0x4000, 0x0400, 0 },
  {"lupin3/lp17.bin", 	   0x4800, 0x0800, 0 },
  {"lupin3/lp18.bin", 	   0x5000, 0x0800, 0 }
};

tagRomList superinvRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 6 },
  {"invaders/invaders.g",       0x0800, 0x0800, 0 },
  {"invaders/invaders.f",       0x1000, 0x0800, 0 },
  {"superinv/02",               0x0800, 0x0400, 0 },
  {"invadpt2/pv04",             0x1800, 0x0400, 0 },
  {"superinv/05",               0x1c00, 0x0400, 0 },
};

tagRomList desterthRom[] = {
  {"desterth/36_h.bin",         0x0000, 0x0800, 7 },
  {"desterth/35_g.bin",         0x0800, 0x0800, 0 },
  {"desterth/34_f.bin",         0x1000, 0x0800, 0 },
  {"desterth/33_e.bin",         0x1800, 0x0800, 0 },
  {"desterth/32_d.bin",         0x0000, 0x0800, 4 },
  {"desterth/31_c.bin",         0x0800, 0x0800, 0 },
  {"desterth/42_b.bin",        0x1000, 0x0800, 0 },
  {"desterth/7643-1.cpu",         0x2000, 0x0800, 0 },
  {"desterth/7643-1.cpu",        0x2400, 0x0800, 0 },
};

tagRomList gunfightRom[] = {
  {"gunfight/7609h.bin",      0x0000, 0x0800, 4 },
  {"gunfight/7609g.bin",      0x0400, 0x0800, 0 },
  {"gunfight/7609f.bin",      0x0800, 0x0800, 0 },
  {"gunfight/7609e.bin",      0x0c00, 0x0800, 0 }
};

tagRomList seawolfRom[] = {
  {"seawolf/sw0041.h",      0x0000, 0x0400, 4 },
  {"seawolf/sw0042.g",      0x0400, 0x0400, 0 },
  {"seawolf/sw0043.f",      0x0800, 0x0400, 0 },
  {"seawolf/sw0044.e",      0x0c00, 0x0400, 0 }
};

tagRomList tornbaseRom[] = {
  {"tornbase/tb.h",      0x0000, 0x0800, 3 },
  {"tornbase/tb.g",      0x0800, 0x0800, 0 },
  {"tornbase/tb.f",      0x1000, 0x0800, 0 }
};

tagRomList mazeRom[] = {
  {"maze/maze.h",      0x0000, 0x0800, 2 },
  {"maze/maze.g",      0x0800, 0x0800, 0 }
};

tagRomList boothillRom[] = {
  {"boothill/romh.cpu",       0x0000, 0x0800, 4 },
  {"boothill/romg.cpu",       0x0800, 0x0800, 0 },
  {"boothill/romf.cpu",       0x1000, 0x0800, 0 },
  {"boothill/rome.cpu",       0x1800, 0x0800, 0 }
};

tagRomList checkmatRom[] = {
  {"checkmat/checkmat.h",      0x0000, 0x0400, 4 },
  {"checkmat/checkmat.g",      0x0400, 0x0400, 0 },
  {"checkmat/checkmat.f",      0x0800, 0x0400, 0 },
  {"checkmat/checkmat.e",      0x0c00, 0x0400, 0 }
};

tagRomList desertguRom[] = {
  {"desertgu/9316.1h",      0x0000, 0x0800, 4 },
  {"desertgu/9316.1g",      0x0800, 0x0800, 0 },
  {"desertgu/9316.1f",      0x1000, 0x0800, 0 },
  {"desertgu/desertgu.e",      0x1800, 0x0800, 0 }
};

tagRomList dplayRom[] = {
  {"dplay/dplay619.h",      0x0000, 0x0800, 4 },
  {"dplay/dplay619.g",      0x0800, 0x0800, 0 },
  {"dplay/dplay619.f",      0x1000, 0x0800, 0 },
  {"dplay/dplay619.e",      0x1800, 0x0800, 0 }
};

tagRomList lagunarRom[] = {
  {"lagunar/lagunar.h",      0x0000, 0x0800, 4 },
  {"lagunar/lagunar.g",      0x0800, 0x0800, 0 },
  {"lagunar/lagunar.f",      0x1000, 0x0800, 0 },
  {"lagunar/lagunar.e",      0x1800, 0x0800, 0 }
};

tagRomList gmissileRom[] = {
  {"gmissile/gm_623.h",      0x0000, 0x0800, 4 },
  {"gmissile/gm_623.g",      0x0800, 0x0800, 0 },
  {"gmissile/gm_623.f",      0x1000, 0x0800, 0 },
  {"gmissile/gm_623.e",      0x1800, 0x0800, 0 }
};

tagRomList m4Rom[] = {
  {"m4/m4.h",      0x0000, 0x0800, 4 },
  {"m4/m4.g",      0x0800, 0x0800, 0 },
  {"m4/m4.f",      0x1000, 0x0800, 0 },
  {"m4/m4.e",      0x1800, 0x0800, 0 }
};

tagRomList clownsRom[] = {
  {"clowns/h2.cpu",       0x0000, 0x0400, 6 },
  {"clowns/g2.cpu",       0x0400, 0x0400, 0 },
  {"clowns/f2.cpu",       0x0800, 0x0400, 0 },
  {"clowns/e2.cpu",       0x0c00, 0x0400, 0 },
  {"clowns/d2.cpu",       0x1000, 0x0400, 0 },
  {"clowns/c2.cpu",       0x1400, 0x0400, 0 }
};

tagRomList clowns1Rom[] = {
  {"clowns1/clownsv1.h",       0x0000, 0x0400, 6 },
  {"clowns1/clownsv1.g",       0x0400, 0x0400, 0 },
  {"clowns1/clownsv1.f",       0x0800, 0x0400, 0 },
  {"clowns1/clownsv1.e",       0x0c00, 0x0400, 0 },
  {"clowns1/clownsv1.d",       0x1000, 0x0400, 0 },
  {"clowns1/clownsv1.c",       0x1400, 0x0400, 0 }
};

tagRomList einningsRom[] = {
  {"einnings/ei.h",      0x0000, 0x0800, 5 },
  {"einnings/ei.g",      0x0800, 0x0800, 0 },
  {"einnings/ei.f",      0x1000, 0x0800, 0 },
  {"einnings/ei.e",      0x1800, 0x0800, 0 },
  {"einnings/ei.b",      0x5000, 0x0800, 0 },
};

tagRomList shuffleRom[] = {
  {"shuffle/shuffle.h",      0x0000, 0x0800, 4 },
  {"shuffle/shuffle.g",      0x0800, 0x0800, 0 },
  {"shuffle/shuffle.f",      0x1000, 0x0800, 0 },
  {"shuffle/shuffle.e",      0x1800, 0x0800, 0 }
};

tagRomList spcenctrRom[] = {
  {"spcenctr/4m33.h",       0x0000, 0x0800, 8 },
  {"spcenctr/4m32.g",       0x0800, 0x0800, 0 },
  {"spcenctr/4m31.f",       0x1000, 0x0800, 0 },
  {"spcenctr/4m30.e",       0x1800, 0x0800, 0 },
  {"spcenctr/4m29.d",       0x2000, 0x0800, 0 },
  {"spcenctr/4m28.c",       0x2800, 0x0800, 0 },
  {"spcenctr/4m27.b",       0x5000, 0x0800, 0 },
  {"spcenctr/4m26.a",       0x5800, 0x0800, 0 }
};

tagRomList dogpatchRom[] = {
  {"dogpatch/dogpatch.h",      0x0000, 0x0800, 4 },
  {"dogpatch/dogpatch.g",      0x0800, 0x0800, 0 },
  {"dogpatch/dogpatch.f",      0x1000, 0x0800, 0 },
  {"dogpatch/dogpatch.e",      0x1800, 0x0800, 0 }
};

tagRomList galxwarsRom[] = {
  {"galxwars/univgw3.0",       0x0000, 0x0400, 6 },
  {"galxwars/univgw4.1",       0x0400, 0x0400, 0 },
  {"galxwars/univgw5.2",       0x0800, 0x0400, 0 },
  {"galxwars/univgw6.3",       0x0c00, 0x0400, 0 },
  {"galxwars/univgw1.4",       0x4000, 0x0400, 0 },
  {"galxwars/univgw2.5",       0x4400, 0x0400, 0 }
};

tagRomList galxwars2Rom[] = {
  {"galxwars2/3192.h6",       0x0000, 0x1000, 6 },
  {"galxwars/univgw4.1",       0x0400, 0x0400, 0 },
  {"galxwars/univgw5.2",       0x0800, 0x0400, 0 },
  {"galxwars/univgw6.3",       0x0c00, 0x0400, 0 },
  {"galxwars2/3193.h7",       0x4000, 0x1000, 0 },
  {"galxwars/univgw2.5",       0x4400, 0x0400, 0 }
};

tagRomList phantom2Rom[] = {
  {"phantom2/phantom2.h",      0x0000, 0x0800, 5 },
  {"phantom2/phantom2.g",      0x0800, 0x0800, 0 },
  {"phantom2/phantom2.f",      0x1000, 0x0800, 0 },
  {"phantom2/phantom2.e",      0x1800, 0x0800, 0 },
  {"phantom2/p2clouds.f2",      0x2000, 0x0800, 0 },
};

tagRomList zzzapRom[] = {
  {"280zzzap/zzzaph",      0x0000, 0x0400, 6 },
  {"280zzzap/zzzapg",      0x0400, 0x0400, 0 },
  {"280zzzap/zzzapf",      0x0800, 0x0400, 0 },
  {"280zzzap/zzzape",      0x0c00, 0x0400, 0 },
  {"280zzzap/zzzapd",      0x1000, 0x0400, 0 },
  {"280zzzap/zzzapc",      0x1400, 0x0400, 0 }
};

tagRomList blueshrkRom[] = {
  {"blueshrk/blueshrk.h",      0x0000, 0x0800, 3 },
  {"blueshrk/blueshrk.g",      0x0800, 0x0800, 0 },
  {"blueshrk/blueshrk.f",      0x1000, 0x0800, 0 }
};

tagRomList invad2ctRom[] = {
  {"invad2ct/invad2ct.h",       0x0000, 0x0800, 6 },
  {"invad2ct/invad2ct.g",       0x0800, 0x0800, 0 },
  {"invad2ct/invad2ct.f",       0x1000, 0x0800, 0 },
  {"invad2ct/invad2ct.e",       0x1800, 0x0800, 0 },
  {"invad2ct/invad2ct.b",       0x5000, 0x0400, 0 },
  {"invad2ct/invad2ct.a",       0x5800, 0x0400, 0 }
};

tagRomList bowlerRom[] = {
  {"bowler/h.cpu",      0x0000, 0x0800, 5 },
  {"bowler/g.cpu",      0x0800, 0x0800, 0 },
  {"bowler/f.cpu",      0x1000, 0x0800, 0 },
  {"bowler/e.cpu",      0x1800, 0x0800, 0 },
  {"bowler/d.cpu",      0x4000, 0x0800, 0 }
};

tagRomList polarisaRom[] = {
  {"polarisa/ps01-1",     0x0000, 0x0800, 7 },
  {"polarisa/ps-09",     0x0800, 0x0800, 0 },
  {"polarisa/ps03-1",     0x1000, 0x0800, 0 },
  {"polarisa/ps-04",     0x1800, 0x0800, 0 },
  {"polarisa/ps-05",     0x4000, 0x0800, 0 },
  {"polarisa/ps-10",     0x4800, 0x0800, 0 },
  {"polarisa/ps26", 0x5000, 0x0800, 0 },
  {"polarisa/ps07", 0x6000, 0x0400, 0 },
  {"polarisa/mb7052.2c", 0x7000, 0x0100, 0 },
};

tagRomList polarisRom[] = {
  {"polaris/ps01-1.30",     0x0000, 0x0800, 7 },
  {"polaris/ps09.36",     0x0800, 0x0800, 0 },
  {"polaris/ps08.1b",     0x1000, 0x0800, 0 },
  {"polaris/ps04.37",     0x1800, 0x0800, 0 },
  {"polaris/ps05.32",     0x4000, 0x0800, 0 },
  {"polaris/ps10.38",     0x4800, 0x0800, 0 },
  {"polaris/ps07.2c", 0x5000, 0x0100, 0 }
};

tagRomList schasercvRom[] = {
  {"schasercv/1",       0x0000, 0x0400, 11 },
  {"schasercv/2",       0x0400, 0x0400, 0 },
  {"schasercv/3",       0x0800, 0x0400, 0 },
  {"schasercv/4",       0x0c00, 0x0400, 0 },
  {"schasercv/5",       0x1000, 0x0400, 0 },
  {"schasercv/6",       0x1400, 0x0400, 0 },
  {"schasercv/7",       0x1800, 0x0400, 0 },
  {"schasercv/8",       0x1c00, 0x0400, 0 },
  {"schasercv/9",       0x4000, 0x0400, 0 },
  {"schasercv/10",       0x4400, 0x0400, 0 },
  {"schasercv/cv01",       0x5000, 0x0400, 0 },
  {"schasercv/cv02",       0x5400, 0x0400, 0 }
};

tagRomList grescueRom[] = {
  {"lrescue/lrescue.1",       0x0000, 0x0800, 8 },
  {"lrescue/lrescue.2",       0x0800, 0x0800, 0 },
  {"lrescue/lrescue.3",       0x1000, 0x0800, 0 },
  {"grescue/grescue.4",       0x1800, 0x0800, 0 },
  {"grescue/grescue.5",       0x4000, 0x0800, 0 },
  {"lrescue/lrescue.6",       0x4800, 0x0800, 0 },
  {"lrescue/7643-1.cpu",      0x5000, 0x0800, 0 },
  {"lrescue/7643-1.cpu",      0x5400, 0x0800, 0 }
};

tagRomList spcewarsRom[] = {
  {"spcewars/sanritsu.1",       0x0000, 0x0400, 8 },
  {"spcewars/sanritsu.2",       0x0400, 0x0400, 0 },
  {"spcewr3/ic35.bin",       0x0800, 0x0800, 0 },
  {"spcewars/sanritsu.5",       0x1000, 0x0400, 0 },
  {"spcewars/sanritsu.6",       0x1400, 0x0400, 0 },
  {"spcewars/sanritsu.7",       0x1800, 0x0400, 0 },
  {"spcewars/sanritsu.8",       0x1c00, 0x0400, 0 },
  {"spcewars/sanritsu.9",       0x4000, 0x0400, 0 }
};

tagRomList rollingcRom[] = {
  {"rollingc/rc01.bin",       0x0000, 0x0400, 12 },
  {"rollingc/rc02.bin",       0x0400, 0x0400, 0 },
  {"rollingc/rc03.bin",       0x0800, 0x0400, 0 },
  {"rollingc/rc04.bin",       0x0c00, 0x0400, 0 },
  {"rollingc/rc05.bin",       0x1000, 0x0400, 0 },
  {"rollingc/rc06.bin",       0x1400, 0x0400, 0 },
  {"rollingc/rc07.bin",       0x1800, 0x0400, 0 },
  {"rollingc/rc08.bin",       0x1c00, 0x0400, 0 },
  {"rollingc/rc09.bin",       0x4000, 0x0400, 0 },
  {"rollingc/rc10.bin",       0x4800, 0x0400, 0 },
  {"rollingc/rc11.bin",       0x5000, 0x0400, 0 },
  {"rollingc/rc12.bin",       0x5800, 0x0400, 0 }
};

tagRomList darthvdrRom[] = {
  {"darthvdr/rom0",       0x0000, 0x0400, 6 },
  {"darthvdr/rom1",       0x0400, 0x0400, 0 },
  {"darthvdr/rom2",       0x0800, 0x0400, 0 },
  {"darthvdr/rom3",       0x0c00, 0x0400, 0 },
  {"darthvdr/rom4",       0x1000, 0x0400, 0 },
  {"darthvdr/rom5",       0x1400, 0x0400, 0 },
};

tagRomList schaserRom[] = {
  {"schaser/rt13.bin", 0x0000, 0x0400, 10 },
  {"schaser/rt14.bin", 0x0400, 0x0400, 0 },
  {"schaser/rt15.bin", 0x0800, 0x0400, 0 },
  {"schaser/rt16.bin", 0x0C00, 0x0400, 0 },
  {"schaser/rt17.bin", 0x1000, 0x0400, 0 },
  {"schaser/rt18.bin", 0x1400, 0x0400, 0 },
  {"schaser/rt19.bin", 0x1800, 0x0400, 0 },
  {"schaser/rt20.bin", 0x1C00, 0x0400, 0 },
  {"schaser/rt21.bin", 0x4000, 0x0400, 0 },
  {"schaser/rt22.bin", 0x4400, 0x0400, 0 }
};

tagRomList moonbaseRom[] = {
  {"moonbase/ze3-1.a4",       0x0000, 0x0400, 10 },
  {"moonbase/ze3-2.c4",       0x0400, 0x0400, 0 },
  {"moonbase/ze3-3.e4",       0x0800, 0x0400, 0 },
  {"moonbase/ze3-4.f4",       0x0c00, 0x0400, 0 },
  {"moonbase/ze3-5.h4",       0x1000, 0x0400, 0 },
  {"moonbase/ze3-6.14",       0x1400, 0x0400, 0 },
  {"moonbase/ze3-7.a5",      0x1800, 0x0400, 0 },
  {"moonbase/ze3-8.c5",      0x1c00, 0x0400, 0 },
  {"moonbase/ze3-9.e5",      0x4000, 0x0400, 0 },
  {"moonbase/ze3-10.f5",      0x4400, 0x0400, 0 },
  {"moonbase/cv02.h7",      0x0000, 0x0400, 0 },
  {"moonbase/cv01.g7",      0x0400, 0x0400, 0 }
};

tagRomList earthinvRom[] = {
  {"searthin/Earthinv.h",       0x0000, 0x0800, 6 },
  {"searthin/Earthinv.g",       0x0800, 0x0800, 0 },
  {"searthin/Earthinv.f",       0x1000, 0x0800, 0 },
  {"searthin/Earthinv.e",       0x1800, 0x0800, 0 },
  {"invadpt2/pv04",               0x1800, 0x0800, 0 },
  {"invaddlx/invdelux.h",               0x0000, 0x0800, 0 },
};
*/

// TODO: Remake Discrete Logic Simulators Using SDL

tagRomList hockeytvRom[] = {
};

tagRomList pongdblsRom[] = {
};

tagRomList pongRom[] = {
};
