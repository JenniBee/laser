#include "laser.h"


tagRomList invadersRom[] = {
  {"invaders/invaders.h", 0x0000, 0x0800, 4 },
  {"invaders/invaders.g", 0x0800, 0x0800, 0 },
  {"invaders/invaders.f", 0x1000, 0x0800, 0 },
  {"invaders/invaders.e", 0x1800, 0x0800, 0 }
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

tagRomList sinvemagRom[] = {
  {"sinvemag/sv0h.bin",    0x0000, 0x0400, 6 },
  {"sinvemag/emag_si.b",   0x0400, 0x0400, 0 },
  {"sinvemag/emag_si.c",   0x0800, 0x0400, 0 },
  {"sinvemag/emag_si.d",   0x1400, 0x0400, 0 },
  {"sinvemag/emag_si.e",   0x1800, 0x0400, 0 },
  {"sinvemag/emag_si.f",   0x1c00, 0x0400, 0 },
};

tagRomList lupin3Rom[] = {
  {"lupin3/lp12.bin",      0x0000, 0x0800, 7 },
  {"lupin3/lp13.bin",      0x0800, 0x0800, 0 },
  {"lupin3/lp14.bin",      0x1000, 0x0800, 0 },
  {"lupin3/lp15.bin",      0x1800, 0x0800, 0 },
  {"lupin3/lp16.bin",      0x4000, 0x0400, 0 },
  {"lupin3/lp17.bin", 	   0x4800, 0x0800, 0 },
  {"lupin3/lp18.bin", 	   0x5000, 0x0800, 0 }
};

tagRomList invaddlxRom[] = {
  {"invaddlx/invdelux.h",       0x0000, 0x0800, 5 },
  {"invaddlx/invdelux.g",       0x0800, 0x0800, 0 },
  {"invaddlx/invdelux.f",       0x1000, 0x0800, 0 },
  {"invaddlx/invdelux.e",       0x1800, 0x0800, 0 },
  {"invaddlx/invdelux.d",       0x4000, 0x0800, 0 }
};

tagRomList invadpt2Rom[] = {
  {"invadpt2/pv.01",      0x0000, 0x0800, 7 },
  {"invadpt2/pv.02",      0x0800, 0x0800, 0 },
  {"invadpt2/pv.03",      0x1000, 0x0800, 0 },
  {"invadpt2/pv.04",      0x1800, 0x0800, 0 },
  {"invadpt2/pv.05",      0x4000, 0x0400, 0 },
  {"invaddlx/invdelux.e", 0x1800, 0x0800, 0 },
  {"invaddlx/invdelux.d", 0x4000, 0x0800, 0 }
};

tagRomList superinvRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 6 },
  {"invaders/invaders.g",       0x0800, 0x0800, 0 },
  {"invaders/invaders.f",       0x1000, 0x0800, 0 },
  {"superinv/02",               0x0800, 0x0400, 0 },
  {"invadpt2/04",               0x1800, 0x0400, 0 },
  {"invaddlx/05",               0x1c00, 0x0400, 0 },
};

tagRomList earthinvRom[] = {
  {"earthinv/Earthinv.h",       0x0000, 0x0800, 6 },
  {"earthinv/Earthinv.g",       0x0800, 0x0800, 0 },
  {"earthinv/Earthinv.f",       0x1000, 0x0800, 0 },
  {"earthinv/Earthinv.e",       0x1800, 0x0800, 0 },
  {"invadpt2/04",               0x1800, 0x0400, 0 },
  {"invaddlx/05",               0x1c00, 0x0400, 0 },
};

tagRomList sicvRom[] = {
  {"SI_CV/Cv17.bin",    0x0000, 0x0800, 4 },
  {"SI_CV/Cv18.bin",    0x0800, 0x0800, 0 },
  {"SI_CV/Cv19.bin",    0x1000, 0x0800, 0 },
  {"SI_CV/Cv20.bin",    0x1800, 0x0800, 0 },
};

tagRomList destinatRom[] = {
  {"destinat/36_h.bin",         0x0000, 0x0800, 7 },
  {"destinat/35_g.bin",         0x0800, 0x0800, 0 },
  {"destinat/34_f.bin",         0x1000, 0x0800, 0 },
  {"destinat/33_e.bin",         0x1800, 0x0800, 0 },
  {"destinat/32_d.bin",         0x0000, 0x0800, 4 },
  {"destinat/31_c.bin",         0x0800, 0x0800, 0 },
  {"destinatx/42_b.bin",        0x1000, 0x0800, 0 },
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

tagRomList starwRom[] = {
  {"starw/roma",      0x0000, 0x0400, 6 },
  {"starw/romb",      0x0400, 0x0400, 0 },
  {"starw/romc",      0x0800, 0x0400, 0 },
  {"starw/romd",      0x1400, 0x0400, 0 },
  {"starw/rome",      0x1800, 0x0400, 0 },
  {"starw/romf",      0x1c00, 0x0400, 0 },
};

tagRomList alieninvRom[] = {
  {"alieninv/1h.bin",      0x0000, 0x0800, 4 },
  {"alieninv/1g.bin",      0x0800, 0x0800, 0 },
  {"alieninv/1f.bin",      0x1000, 0x0800, 0 },
  {"alieninv/1e.bin",      0x1800, 0x0800, 0 },
};

tagRomList ozmawarsRom[] = {
  {"ozmawars/mw01",      0x0000, 0x0800, 6 },
  {"ozmawars/mw02",      0x0800, 0x0800, 0 },
  {"ozmawars/mw03",      0x1000, 0x0800, 0 },
  {"ozmawars/mw04",      0x1800, 0x0800, 0 },
  {"ozmawars/mw05",      0x4000, 0x0800, 0 },
  {"ozmawars/mw06",      0x4800, 0x0800, 0 },
};

tagRomList ozmawar2Rom[] = {
  {"ozmawars/mw01",     0x0000, 0x0800, 9 },
  {"ozmawars/mw02",     0x0800, 0x0800, 0 },
  {"ozmawars/oz5",      0x1000, 0x0400, 0 },
  {"ozmawars/oz6",      0x1400, 0x0400, 0 },
  {"ozmawars/oz7",      0x0800, 0x0400, 0 },
  {"ozmawars/oz8",      0x1c00, 0x0400, 0 },
  {"ozmawars/mw05",     0x4000, 0x0800, 0 },
  {"ozmawars/oz11",     0x4800, 0x0400, 0 },
  {"ozmawars/oz12",     0x4c00, 0x0400, 0 },
};

tagRomList theendsRom[] = {
  {"theends/IC13",      0x0000, 0x0800, 10 },
  {"theends/IC14",      0x0800, 0x0800, 0 },
  {"theends/IC15",      0x1000, 0x0800, 0 },
  {"theends/IC16",      0x1800, 0x0800, 0 },
  {"theends/IC17",      0x2000, 0x0800, 0 },
  {"theends/IC18",      0x2800, 0x0800, 0 },
  {"theends/IC17",      0x3000, 0x0800, 0 },
  {"theends/IC18",      0x3800, 0x0800, 0 },
  {"theends/IC30",      0x5000, 0x0800, 0 },
  {"theends/IC31",      0x5800, 0x0800, 0 }
};

tagRomList froggersRom[] = {
  {"froggers/vid_d2.bin",       0x0000, 0x0800, 11 },
  {"froggers/vid_e2.bin",       0x0800, 0x0800, 0 },
  {"froggers/vid_f2.bin",       0x1000, 0x0800, 0 },
  {"froggers/vid_h2.bin",       0x1800, 0x0800, 0 },
  {"froggers/vid_j2.bin",       0x2000, 0x0800, 0 },
  {"froggers/vid_l2.bin",       0x2800, 0x0800, 0 },
  {"frogger/frogger.608",      0x3000, 0x0800, 0 },
  {"frogger/frogger.609",      0x3800, 0x0800, 0 },
  {"frogger/frogger.610",      0x4000, 0x0800, 0 },
  {"froggers/epr-1036.1k",      0x5000, 0x0800, 0 },
  {"frogger/frogger.607",      0x5800, 0x0800, 0 }
};


tagRomList theendRom[] = {
  {"theend/ic13_1t.bin",       0x0000, 0x0800, 8 },
  {"theend/ic14_2t.bin",       0x0800, 0x0800, 0 },
  {"theend/ic15_3t.bin",       0x1000, 0x0800, 0 },
  {"theend/ic16_4t.bin",       0x1800, 0x0800, 0 },
  {"theend/ic17_5t.bin",       0x2000, 0x0800, 0 },
  {"theend/ic18_6t.bin",       0x2800, 0x0800, 0 },
  {"theend/ic30_2c.bin",       0x5000, 0x0800, 0 },
  {"theend/ic31_1c.bin",       0x5800, 0x0800, 0 }
};

tagRomList scrambleRom[] = {
  {"scramble/2d.k",     0x0000, 0x0800, 10 },
  {"scramble/2e.k",     0x0800, 0x0800, 0 },
  {"scramble/2f.k",     0x1000, 0x0800, 0 },
  {"scramble/2h.k",     0x1800, 0x0800, 0 },
  {"scramble/2j.k",     0x2000, 0x0800, 0 },
  {"scramble/2l.k",     0x2800, 0x0800, 0 },
  {"scramble/2m.k",     0x3000, 0x0800, 0 },
  {"scramble/2p.k",     0x3800, 0x0800, 0 },
  {"scramble/5f.k",     0x5000, 0x0800, 0 },
  {"scramble/5h.k",     0x5800, 0x0800, 0 }
};

tagRomList atlantisRom[] = {
  {"atlantis/2c",       0x0000, 0x0800, 8 },
  {"atlantis/2e",       0x0800, 0x0800, 0 },
  {"atlantis/2f",       0x1000, 0x0800, 0 },
  {"atlantis/2h",       0x1800, 0x0800, 0 },
  {"atlantis/2j",       0x2000, 0x0800, 0 },
  {"atlantis/2l",       0x2800, 0x0800, 0 },
  {"atlantis/5f",       0x5000, 0x0800, 0 },
  {"atlantis/5h",       0x5800, 0x0800, 0 }
};

tagRomList lrescueRom[] = {
  {"lrescue/lrescue.1", 0x0000, 0x0800, 6 },
  {"lrescue/lrescue.2", 0x0800, 0x0800, 0 },
  {"lrescue/lrescue.3", 0x1000, 0x0800, 0 },
  {"lrescue/lrescue.4", 0x1800, 0x0800, 0 },
  {"lrescue/lrescue.5", 0x4000, 0x0800, 0 },
  {"lrescue/lrescue.6", 0x4800, 0x0800, 0 }
};

tagRomList galaxywarsRom[] = {
  {"galxwars/galxwars.0", 0x0000, 0x0400, 6 },
  {"galxwars/galxwars.1", 0x0400, 0x0400, 0 },
  {"galxwars/galxwars.2", 0x0800, 0x0400, 0 },
  {"galxwars/galxwars.3", 0x0C00, 0x0400, 0 },
  {"galxwars/galxwars.4", 0x4000, 0x0400, 0 },
  {"galxwars/galxwars.5", 0x4400, 0x0400, 0 }
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

tagRomList spaceattRom[] = {
  {"spaceatt/h",          0x0000, 0x0400, 6 },
  {"spaceatt/sv02.bin",   0x0400, 0x0400, 0 },
  {"spaceatt/f",          0x0800, 0x0400, 0 },
  {"spaceatt/c",          0x1400, 0x0400, 0 },
  {"spaceatt/b",          0x1800, 0x0400, 0 },
  {"spaceatt/a",          0x1C00, 0x0400, 0 }
};

tagRomList spaceattack2Rom[] = {
  {"spaceat2/spaceatt.h", 0x0000, 0x0800, 4 },
  {"spaceat2/spaceatt.g", 0x0800, 0x0800, 0 },
  {"spaceat2/spaceatt.f", 0x1000, 0x0800, 0 },
  {"spaceat2/spaceatt.e", 0x1800, 0x0800, 0 }
};

tagRomList invrevengeRom[] = {
  {"invrvnge/invrvnge.h", 0x0000, 0x0800, 4 },
  {"invrvnge/invrvnge.g", 0x0800, 0x0800, 0 },
  {"invrvnge/invrvnge.f", 0x1000, 0x0800, 0 },
  {"invrvnge/invrvnge.e", 0x1800, 0x0800, 0 }
};

tagRomList polarisRom[] = {
  {"polaris/ps-01",     0x0000, 0x0800, 7 },
  {"polaris/ps-09",     0x0800, 0x0800, 0 },
  {"polaris/ps-08",     0x1000, 0x0800, 0 },
  {"polaris/ps-04",     0x1800, 0x0800, 0 },
  {"polaris/ps-05",     0x4000, 0x0800, 0 },
  {"polaris/ps-10",     0x4800, 0x0800, 0 },
  {"polaris/mb7052.2c", 0x2400, 0x0100, 0 }
};

tagRomList spclaserRom[] = {
  {"spclaser/la01",       0x0000, 0x0800, 4 },
  {"spclaser/spcewarl.2", 0x0800, 0x0800, 0 },
  {"spclaser/la03",       0x1000, 0x0800, 0 },
  {"spclaser/la04",       0x1800, 0x0800, 0 }
};

tagRomList laserRom[] = {
  {"laser/1.u36",       0x0000, 0x0800, 4 },
  {"laser/2.u35",       0x0800, 0x0800, 0 },
  {"laser/3.u34",       0x1000, 0x0800, 0 },
  {"laser/4.u33",       0x1800, 0x0800, 0 }
};

tagRomList testerRom[] = {
  {"sitv/tv0h.s1",              0x0000, 0x0800, 5 },
  {"sitv/tv02.rp1",             0x0800, 0x0800, 0 },
  {"sitv/tv03.n1",              0x1000, 0x0800, 0 },
  {"sitv/tv04.m1",              0x1800, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};
