#include "laser.h"

tagRomList pongdblsRom[] = {
};

tagRomList pongRom[] = {
};

tagRomList beaminvRom[] = {
  {"invaders/invaders.h", 0x0000, 0x0800, 6 },
  {"invaders/invaders.g", 0x0800, 0x0800, 0 },
  {"invaders/invaders.f", 0x1000, 0x0800, 0 },
  {"beaminv/2a", 0x1800, 0x0800, 0 },
  {"beaminv/1a", 0x4000, 0x0800, 0 },
  {"beaminv/0a", 0x4800, 0x0800, 0 }
};

tagRomList spacefevRom[] = {
  {"spacefev/f1.bin", 0x0000, 0x0400, 9 },
  {"spacefev/f2.bin", 0x0400, 0x0400, 0 },
  {"spacefev/g1.bin", 0x0800, 0x0400, 0 },
  {"spacefev/g2.bin", 0x0c00, 0x0400, 0 },
  {"spacefev/h1.bin", 0x1000, 0x0400, 0 },
  {"spacefev/h2.bin", 0x1400, 0x0400, 0 },
  {"spacefev/i1.bin", 0x1800, 0x0400, 0 },
  {"spacefev/ss3.ic2", 0x2000, 0x0400, 0 },
  {"spacefev/f5.bpr", 0x3000, 0x0020, 0 }
};

tagRomList sfeverbwRom[] = {
  {"sfeverbw/spacefev.f1", 0x0000, 0x0400, 9 },
  {"sfeverbw/spacefev.f2", 0x0400, 0x0400, 0 },
  {"sfeverbw/spacefev.g1", 0x0800, 0x0400, 0 },
  {"sfeverbw/spacefev.g2", 0x0c00, 0x0400, 0 },
  {"sfeverbw/spacefev.h1", 0x1000, 0x0400, 0 },
  {"sfeverbw/spacefev.h2", 0x1400, 0x0400, 0 },
  {"sfeverbw/spacefev.i1", 0x1800, 0x0400, 0 },
  {"sfeverbw/spacefev.i2", 0x1c00, 0x0400, 0 },
  {"sfeverbw/ss3.ic2", 0x2000, 0x0400, 0 }
};

tagRomList sstrangrRom[] = {
  {"sstrangr/hss-01.58", 0x0000, 0x0400, 8 },
  {"sstrangr/hss-02.59", 0x0400, 0x0400, 0 },
  {"sstrangr/hss-03.60", 0x0800, 0x0400, 0 },
  {"sstrangr/hss-04.61", 0x0c00, 0x0400, 0 },
  {"sstrangr/hss-05.62", 0x1000, 0x0400, 0 },
  {"sstrangr/hss-06.63", 0x1400, 0x0400, 0 },
  {"sstrangr/hss-07.64", 0x1800, 0x0400, 0 },
  {"sstrangr/hss-08.65", 0x1c00, 0x0400, 0 }
};

tagRomList sstrngr2Rom[] = {
  {"sstrngr2/4764.09", 0x0000, 0x2000, 3 },
  {"sstrngr2/2708.10", 0x6000, 0x0400, 0 },
  {"sstrngr2/2708.15", 0x7000, 0x0400, 0 }
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

tagRomList spcenctrRom[] = {
  {"spcenctr/4m33.cpu",       0x0000, 0x0800, 8 },
  {"spcenctr/4m32.cpu",       0x0800, 0x0800, 0 },
  {"spcenctr/4m31.cpu",       0x1000, 0x0800, 0 },
  {"spcenctr/4m30.cpu",       0x1800, 0x0800, 0 },
  {"spcenctr/4m29.cpu",       0x2000, 0x0800, 0 },
  {"spcenctr/4m28.cpu",       0x2800, 0x0800, 0 },
  {"spcenctr/4m27.cpu",       0x5000, 0x0800, 0 },
  {"spcenctr/4m26.cpu",       0x5800, 0x0800, 0 }
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

tagRomList invrevengeRom[] = {
  {"invrvnge/invrvnge.h", 0x0000, 0x0800, 4 },
  {"invrvnge/invrvnge.g", 0x0800, 0x0800, 0 },
  {"invrvnge/invrvnge.f", 0x1000, 0x0800, 0 },
  {"invrvnge/invrvnge.e", 0x1800, 0x0800, 0 }
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
  {"polaris/ps-01",     0x0000, 0x0800, 7 },
  {"polaris/ps-09",     0x0800, 0x0800, 0 },
  {"polaris/ps-08",     0x1000, 0x0800, 0 },
  {"polaris/ps-04",     0x1800, 0x0800, 0 },
  {"polaris/ps-05",     0x4000, 0x0800, 0 },
  {"polaris/ps-10",     0x4800, 0x0800, 0 },
  {"polaris/mb7052.2c", 0x5000, 0x0100, 0 }
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

tagRomList invadersRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 4 },
  {"invaders/invaders.g",       0x0800, 0x0800, 0 },
  {"invaders/invaders.f",       0x1000, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};

tagRomList earthinvRom[] = {
  {"earthinv/Earthinv.h",       0x0000, 0x0800, 6 },
  {"earthinv/Earthinv.g",       0x0800, 0x0800, 0 },
  {"earthinv/Earthinv.f",       0x1000, 0x0800, 0 },
  {"earthinv/Earthinv.e",       0x1800, 0x0800, 0 },
  {"invadpt2/04",               0x1800, 0x0400, 0 },
  {"invaddlx/05",               0x1c00, 0x0400, 0 },
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

tagRomList alieninvRom[] = {
  {"alieninv/1h.bin",      0x0000, 0x0800, 4 },
  {"alieninv/1g.bin",      0x0800, 0x0800, 0 },
  {"alieninv/1f.bin",      0x1000, 0x0800, 0 },
  {"alieninv/1e.bin",      0x1800, 0x0800, 0 },
};

tagRomList sitvRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 5 },
  {"sitv/tv02.rp1",             0x0800, 0x0800, 0 },
  {"sitv/tv03.n1",              0x1000, 0x0800, 0 },
  {"sitv/tv04.m1",              0x1800, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};

tagRomList testerRom[] = {
  {"sitv/tv0h.s1",              0x0000, 0x0800, 5 },
  {"sitv/tv02.rp1",             0x0800, 0x0800, 0 },
  {"sitv/tv03.n1",              0x1000, 0x0800, 0 },
  {"sitv/tv04.m1",              0x1800, 0x0800, 0 },
  {"invaders/invaders.e",       0x1800, 0x0800, 0 }
};

tagRomList sicvRom[] = {
  {"sicv/Cv17.bin",    0x0000, 0x0800, 6 },
  {"sicv/Cv18.bin",    0x0800, 0x0800, 0 },
  {"sicv/Cv19.bin",    0x1000, 0x0800, 0 },
  {"sicv/Cv20.bin",    0x1800, 0x0800, 0 },
  {"sicv/cv01_1.bin",  0x2000, 0x0400, 0 },
  {"sicv/cv02_2.bin",  0x2400, 0x0400, 0 }
};

tagRomList sisvRom[] = {
  {"sisv/sv0h.bin",    0x0000, 0x0400, 7 },
  {"sisv/sv02.bin",    0x0400, 0x0400, 0 },
  {"invaders/invaders.g",    0x0800, 0x0800, 0 },
  {"invaders/invaders.f",    0x1000, 0x0800, 0 },
  {"sitv/tv04.m1",  0x1800, 0x0800, 0 },
  {"sicv/cv01_1.bin",  0x2000, 0x0400, 0 },
  {"sicv/cv02_2.bin",  0x2400, 0x0400, 0 }
};

tagRomList sisv2Rom[] = {
  {"sisv/sv0h.bin",    0x0000, 0x0400, 8 },
  {"sisv2/emag_si.b",    0x0400, 0x0400, 0 },
  {"sisv2/sv12",    0x0800, 0x0400, 0 },
  {"invaders/invaders.f",    0x1000, 0x0800, 0 },
  {"sisv2/sv13",  0x1800, 0x0400, 0 },
  {"sisv2/sv14",  0x1c00, 0x0400, 0 },
  {"sicv/cv01_1.bin",  0x2000, 0x0400, 0 },
  {"sicv/cv02_2.bin",  0x2400, 0x0400, 0 }
};

tagRomList spcekingRom[] = {
  {"invaders/invaders.h",       0x0000, 0x0800, 4 },
  {"spceking/spcekng2",       0x0800, 0x0800, 0 },
  {"spceking/spcekng3",       0x1000, 0x0800, 0 },
  {"spceking/spcekng4",       0x1800, 0x0800, 0 }
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

tagRomList spcewr3Rom[] = {
  {"spcewr3/ic36.bin",       0x0000, 0x0800, 5 },
  {"spcewr3/ic35.bin",       0x0800, 0x0800, 0 },
  {"spcewr3/ic34.bin",       0x1000, 0x0800, 0 },
  {"spcewr3/ic33.bin",       0x1800, 0x0800, 0 },
  {"spcewr3/ic32.bin",       0x4000, 0x0400, 0 }
};

tagRomList invader1Rom[] = {
  {"invader1/c01",       0x0000, 0x0400, 7 },
  {"invader1/c02",       0x0400, 0x0400, 0 },
  {"invader1/c03",       0x0800, 0x0400, 0 },
  {"invader1/c07",       0x1000, 0x0400, 0 },
  {"invader1/c04",       0x1400, 0x0400, 0 },
  {"invader1/c05",       0x1800, 0x0400, 0 },
  {"invader1/sv06.bin",  0x1c00, 0x0400, 0 }
};

tagRomList jspecterRom[] = {
  {"jspecter/3305.u6",       0x0000, 0x1000, 2 },
  {"jspecter/3306.u7",       0x1400, 0x1000, 0 }
};

tagRomList jspectr2Rom[] = {
  {"jspectr2/unksi.b2",       0x0000, 0x1000, 2 },
  {"jspectr2/unksi.a2",       0x1400, 0x1000, 0 }
};

tagRomList moonbaseRom[] = {
  {"moonbase/pv.01",       0x0000, 0x0800, 8 },
  {"moonbase/pv.02",       0x0800, 0x0800, 0 },
  {"moonbase/ze3-5.bin",       0x1000, 0x0400, 0 },
  {"moonbase/ze3-6.bin",       0x1400, 0x0400, 0 },
  {"moonbase/ze3-7.bin",       0x1800, 0x0400, 0 },
  {"moonbase/ze3-8.bin",       0x1c00, 0x0400, 0 },
  {"moonbase/ze3-9.bin",       0x4000, 0x0400, 0 },
  {"moonbase/ze3-10.bin",      0x4400, 0x0400, 0 }
};

tagRomList invad2ctRom[] = {
  {"invad2ct/invad2ct.h",       0x0000, 0x0800, 6 },
  {"invad2ct/invad2ct.g",       0x0800, 0x0800, 0 },
  {"invad2ct/invad2ct.f",       0x1000, 0x0800, 0 },
  {"invad2ct/invad2ct.e",       0x1800, 0x0800, 0 },
  {"invad2ct/invad2ct.b",       0x5000, 0x0400, 0 },
  {"invad2ct/invad2ct.a",       0x5800, 0x0400, 0 }
};

tagRomList invrvngeRom[] = {
  {"invrvnge/invrvnge.h",       0x0000, 0x0800, 4 },
  {"invrvnge/invrvnge.g",       0x0800, 0x0800, 0 },
  {"invrvnge/invrvnge.f",       0x1000, 0x0800, 0 },
  {"invrvnge/invrvnge.e",       0x1800, 0x0800, 0 }
};

tagRomList invrvngaRom[] = {
  {"invrvnga/5m.bin",       0x0000, 0x0800, 4 },
  {"invrvnga/5n.bin",       0x0800, 0x0800, 0 },
  {"invrvnga/5p.bin",       0x1000, 0x0800, 0 },
  {"invrvnga/5r.bin",       0x1800, 0x0800, 0 }
};

tagRomList spcewar1Rom[] = {
  {"spcewar1/spcewarl.1",       0x0000, 0x0800, 4 },
  {"spcewar1/spcewarl.1",       0x0800, 0x0800, 0 },
  {"spcewar1/spcewarl.1",       0x1000, 0x0800, 0 },
  {"spcewar1/spcewarl.1",       0x1800, 0x0800, 0 }
};

tagRomList galxwarsRom[] = {
  {"galxwars/univgw3.0",       0x0000, 0x0400, 6 },
  {"galxwars/univgw4.1",       0x0400, 0x0400, 0 },
  {"galxwars/univgw5.2",       0x0800, 0x0400, 0 },
  {"galxwars/univgw6.3",       0x0c00, 0x0400, 0 },
  {"galxwars/univgw1.4",       0x4000, 0x0400, 0 },
  {"galxwars/univgw2.5",       0x4400, 0x0400, 0 }
};

tagRomList galxwar2Rom[] = {
  {"galxwar2/3192.h6",       0x0000, 0x1000, 6 },
  {"galxwars/univgw4.1",       0x0400, 0x0400, 0 },
  {"galxwars/univgw5.2",       0x0800, 0x0400, 0 },
  {"galxwars/univgw6.3",       0x0c00, 0x0400, 0 },
  {"galxwar2/3193.h7",       0x4000, 0x1000, 0 },
  {"galxwars/univgw2.5",       0x4400, 0x0400, 0 }
};

tagRomList galxwartRom[] = {
  {"galxwart/galxwars.0",       0x0000, 0x0400, 6 },
  {"galxwart/galxwars.1",       0x0400, 0x0400, 0 },
  {"galxwart/galxwars.2",       0x0800, 0x0400, 0 },
  {"galxwart/galxwars.3",       0x0c00, 0x0400, 0 },
  {"galxwart/galxwars.4",       0x4000, 0x0400, 0 },
  {"galxwart/galxwars.5",       0x4400, 0x0400, 0 }
};

tagRomList grescueRom[] = {
  {"grescue/lrescue.1",       0x0000, 0x0800, 8 },
  {"grescue/lrescue.2",       0x0800, 0x0800, 0 },
  {"grescue/lrescue.3",       0x1000, 0x0800, 0 },
  {"grescue/lrescue.4",       0x1800, 0x0800, 0 },
  {"grescue/lrescue.5",       0x4000, 0x0800, 0 },
  {"grescue/lrescue.6",       0x4800, 0x0800, 0 },
  {"grescue/7643-1.cpu",      0x5000, 0x0800, 0 },
  {"grescue/7643-1.cpu",      0x5400, 0x0800, 0 }
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

tagRomList boothillRom[] = {
  {"boothill/romh.cpu",       0x0000, 0x0800, 4 },
  {"boothill/romg.cpu",       0x0800, 0x0800, 0 },
  {"boothill/romf.cpu",       0x1000, 0x0800, 0 },
  {"boothill/rome.cpu",       0x1800, 0x0800, 0 }
};

tagRomList schasrcvRom[] = {
  {"schasrcv/1",       0x0000, 0x0400, 11 },
  {"schasrcv/2",       0x0400, 0x0400, 0 },
  {"schasrcv/3",       0x0800, 0x0400, 0 },
  {"schasrcv/4",       0x0c00, 0x0400, 0 },
  {"schasrcv/5",       0x1000, 0x0400, 0 },
  {"schasrcv/6",       0x1400, 0x0400, 0 },
  {"schasrcv/7",       0x1800, 0x0400, 0 },
  {"schasrcv/8",       0x1c00, 0x0400, 0 },
  {"schasrcv/9",       0x4000, 0x0400, 0 },
  {"schasrcv/10",       0x4400, 0x0400, 0 },
  {"schasrcv/cv01",       0x5000, 0x0400, 0 },
  {"schasrcv/cv02",       0x5400, 0x0400, 0 }
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

tagRomList gmissileRom[] = {
  {"gmissile/gm_623.h",      0x0000, 0x0800, 4 },
  {"gmissile/gm_624.g",      0x0800, 0x0800, 0 },
  {"gmissile/gm_625.f",      0x1000, 0x0800, 0 },
  {"gmissile/gm_626.e",      0x1800, 0x0800, 0 }
};

tagRomList seawolfRom[] = {
  {"seawolf/sw0041.h",      0x0000, 0x0400, 4 },
  {"seawolf/sw0042.g",      0x0400, 0x0400, 0 },
  {"seawolf/sw0043.f",      0x0800, 0x0400, 0 },
  {"seawolf/sw0044.e",      0x0c00, 0x0400, 0 }
};

tagRomList lagunarRom[] = {
  {"lagunar/lagunar.h",      0x0000, 0x0800, 4 },
  {"lagunar/lagunar.g",      0x0800, 0x0800, 0 },
  {"lagunar/lagunar.f",      0x1000, 0x0800, 0 },
  {"lagunar/lagunar.e",      0x1800, 0x0800, 0 }
};

tagRomList m4Rom[] = {
  {"m4/m4.h",      0x0000, 0x0800, 4 },
  {"m4/m4.g",      0x0800, 0x0800, 0 },
  {"m4/m4.f",      0x1000, 0x0800, 0 },
  {"m4/m4.e",      0x1800, 0x0800, 0 }
};

tagRomList phantom2Rom[] = {
  {"phantom2/phantom2.h",      0x0000, 0x0800, 5 },
  {"phantom2/phantom2.g",      0x0800, 0x0800, 0 },
  {"phantom2/phantom2.f",      0x1000, 0x0800, 0 },
  {"phantom2/phantom2.e",      0x1800, 0x0800, 0 },
  {"phantom2/pclouds",      0x2000, 0x0800, 0 },
};

tagRomList dogpatchRom[] = {
  {"dogpatch/dogpatch.h",      0x0000, 0x0800, 4 },
  {"dogpatch/dogpatch.g",      0x0800, 0x0800, 0 },
  {"dogpatch/dogpatch.f",      0x1000, 0x0800, 0 },
  {"dogpatch/dogpatch.e",      0x1800, 0x0800, 0 }
};

tagRomList bowlerRom[] = {
  {"bowler/h.cpu",      0x0000, 0x0800, 5 },
  {"bowler/g.cpu",      0x0800, 0x0800, 0 },
  {"bowler/f.cpu",      0x1000, 0x0800, 0 },
  {"bowler/e.cpu",      0x1800, 0x0800, 0 },
  {"bowler/d.cpu",      0x4000, 0x0800, 0 }
};

tagRomList shuffleRom[] = {
  {"shuffle/shuffle.h",      0x0000, 0x0800, 4 },
  {"shuffle/shuffle.g",      0x0800, 0x0800, 0 },
  {"shuffle/shuffle.f",      0x1000, 0x0800, 0 },
  {"shuffle/shuffle.e",      0x1800, 0x0800, 0 }
};

tagRomList blueshrkRom[] = {
  {"blueshrk/blueshrk.h",      0x0000, 0x0800, 3 },
  {"blueshrk/blueshrk.g",      0x0800, 0x0800, 0 },
  {"blueshrk/blueshrk.f",      0x1000, 0x0800, 0 }
};

tagRomList einningsRom[] = {
  {"einnings/ei.h",      0x0000, 0x0800, 5 },
  {"einnings/ei.g",      0x0800, 0x0800, 0 },
  {"einnings/ei.f",      0x1000, 0x0800, 0 },
  {"einnings/ei.e",      0x1800, 0x0800, 0 },
  {"einnings/ei.b",      0x5000, 0x0800, 0 },
};

tagRomList dplayRom[] = {
  {"dplay/dplay.h",      0x0000, 0x0800, 4 },
  {"dplay/dplay.g",      0x0800, 0x0800, 0 },
  {"dplay/dplay.f",      0x1000, 0x0800, 0 },
  {"dplay/dplay.e",      0x1800, 0x0800, 0 }
};

tagRomList mazeRom[] = {
  {"maze/invaders.h",      0x0000, 0x0800, 2 },
  {"maze/invaders.g",      0x0800, 0x0800, 0 }
};

tagRomList tornbaseRom[] = {
  {"tornbase/tb.h",      0x0000, 0x0800, 3 },
  {"tornbase/tb.g",      0x0800, 0x0800, 0 },
  {"tornbase/tb.f",      0x1000, 0x0800, 0 }
};

tagRomList checkmatRom[] = {
  {"checkmat/checkmat.h",      0x0000, 0x0400, 4 },
  {"checkmat/checkmat.g",      0x0400, 0x0400, 0 },
  {"checkmat/checkmat.f",      0x0800, 0x0400, 0 },
  {"checkmat/checkmat.e",      0x0c00, 0x0400, 0 }
};

tagRomList desertguRom[] = {
  {"desertgu/desertgu.h",      0x0000, 0x0800, 4 },
  {"desertgu/desertgu.g",      0x0800, 0x0800, 0 },
  {"desertgu/desertgu.f",      0x1000, 0x0800, 0 },
  {"desertgu/desertgu.e",      0x1800, 0x0800, 0 }
};

tagRomList gunfightRom[] = {
  {"gunfight/7609h.bin",      0x0000, 0x0800, 4 },
  {"gunfight/7609g.bin",      0x0400, 0x0800, 0 },
  {"gunfight/7609f.bin",      0x0800, 0x0800, 0 },
  {"gunfight/7609e.bin",      0x0c00, 0x0800, 0 }
};

tagRomList zzzapRom[] = {
  {"280zzzap/zzzaph",      0x0000, 0x0400, 6 },
  {"280zzzap/zzzapg",      0x0400, 0x0400, 0 },
  {"280zzzap/zzzapf",      0x0800, 0x0400, 0 },
  {"280zzzap/zzzape",      0x0c00, 0x0400, 0 },
  {"280zzzap/zzzapd",      0x1000, 0x0400, 0 },
  {"280zzzap/zzzapc",      0x1400, 0x0400, 0 }
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

tagRomList solfightRom[] = {
  {"solfight/solfight.m",      0x0000, 0x0800, 6 },
  {"solfight/solfight.n",      0x0800, 0x0800, 0 },
  {"solfight/solfight.p",      0x1000, 0x0800, 0 },
  {"solfight/solfight.r",      0x1800, 0x0800, 0 },
  {"solfight/mw05",      0x4000, 0x0800, 0 },
  {"solfight/solfight.t",      0x4800, 0x0800, 0 }
};

tagRomList ballbombRom[] = {
  {"ballbomb/tn01",      0x0000, 0x0800, 7 },
  {"ballbomb/tn02",      0x0800, 0x0800, 0 },
  {"ballbomb/tn03",      0x1000, 0x0800, 0 },
  {"ballbomb/tn04",      0x1800, 0x0800, 0 },
  {"ballbomb/tn05",      0x4000, 0x0800, 0 },
  {"ballbomb/tn06",      0x5000, 0x0400, 0 },
  {"ballbomb/tn07",      0x5400, 0x0400, 0 }
};

tagRomList sheriffRom[] = {
  {"sheriff/f1",              0x0000, 0x0400, 10 },
  {"sheriff/f2",             0x0400, 0x0400, 0 },
  {"sheriff/g1",              0x0800, 0x0400, 0 },
  {"sheriff/g2",              0x0c00, 0x0400, 0 },
  {"sheriff/h1",       0x1000, 0x0400, 0 },
  {"sheriff/h2",       0x1400, 0x0400, 0 },
  {"sheriff/i1",       0x1800, 0x0400, 0 },
  {"sheriff/i2",       0x1c00, 0x0400, 0 },
  {"sheriff/j1",       0x2000, 0x0400, 0 },
  {"sheriff/basnd.u2",       0x3000, 0x0400, 0 }
};

tagRomList bandidoRom[] = {
  {"bandido/baf1-3",              0x0000, 0x0400, 11 },
  {"bandido/f2",             0x0400, 0x0400, 0 },
  {"bandido/g1",              0x0800, 0x0400, 0 },
  {"bandido/g2",              0x0c00, 0x0400, 0 },
  {"bandido/bah1-1",       0x1000, 0x0400, 0 },
  {"bandido/h2",       0x1400, 0x0400, 0 },
  {"bandido/i1",       0x1800, 0x0400, 0 },
  {"bandido/i2",       0x1c00, 0x0400, 0 },
  {"bandido/j1",       0x2000, 0x0400, 0 },
  {"bandido/baj2-2",       0x2400, 0x0400, 0 },
  {"bandido/basnd.u2",       0x3000, 0x0400, 0 }
};

tagRomList helifireRom[] = {
  {"helifire/tub.f1b",              0x0000, 0x0400, 11 },
  {"helifire/tub.f2b",             0x0400, 0x0400, 0 },
  {"helifire/tub.g1b",              0x0800, 0x0400, 0 },
  {"helifire/tub.g2b",              0x0c00, 0x0400, 0 },
  {"helifire/tub.h1b",       0x1000, 0x0400, 0 },
  {"helifire/tub.h2b",       0x1400, 0x0400, 0 },
  {"helifire/tub.i1b",       0x1800, 0x0400, 0 },
  {"helifire/tub.i2b",       0x1c00, 0x0400, 0 },
  {"helifire/tub.j1b",       0x2000, 0x0400, 0 },
  {"helifire/tub.j2b",       0x2400, 0x0400, 0 },
  {"helifire/tub.snd",       0x3000, 0x0400, 0 }
};

tagRomList helifiraRom[] = {
  {"helifira/f1a.bin",              0x0000, 0x0400, 10 },
  {"helifira/f2a.bin",             0x0400, 0x0400, 0 },
  {"helifira/tub.g1b",              0x0800, 0x0400, 0 },
  {"helifira/g2a.bin",              0x0c00, 0x0400, 0 },
  {"helifira/h1a.bin",       0x1000, 0x0400, 0 },
  {"helifira/tub.h2b",       0x1400, 0x0400, 0 },
  {"helifira/tub.i1b",       0x1800, 0x0400, 0 },
  {"helifira/i2a.bin",       0x1c00, 0x0400, 0 },
  {"helifira/tub.j1b",       0x2000, 0x0400, 0 },
  {"helifira/tub.j2b",       0x2400, 0x0400, 0 }
};

