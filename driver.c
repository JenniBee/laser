#include "laser.h"

#define sys_init(NAME) init_##NAME
#define sys_start(NAME) start_##NAME
#define sys_shutdown(NAME) shutdown_##NAME
#define sys_doin(NAME) doin_##NAME
#define sys_doout(NAME) doout_##NAME
#define sys_rdmem(NAME) rdmem_##NAME
#define sys_wrmem(NAME) wrmem_##NAME
#define sys_patch(NAME) patch_##NAME
#define sys_interrupt(NAME) interrupt_##NAME
#define sys_NMI(NAME) NMI_##NAME
#define sys_save_state(NAME) save_state_##NAME
#define sys_load_state(NAME) load_state_##NAME

void rom_invaders();

/* required to determine if a custom one has been made */
int RomsInterrupt;
int RomsRdmem;
int RomsWrmem;

#include "romlist.h"

tagGameList gameList[] = {
  {"polaris",           polarisRom,     init_invaders,  start_invaders,  shutdown_invaders,  interrupt_polaris,   doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"invaders",          invadersRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"yosakdon",          cosmicmoRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"lupin3",            lupin3Rom,      init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_lupin3,    NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"spclaser",          spclaserRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"superinv",          superinvRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"earthinv",          earthinvRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"starw",             starwRom,       init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"alieninv",          alieninvRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"ozmawars",          ozmawarsRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"ozmawar2",          ozmawar2Rom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"sicv",              sicvRom,        init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"invadpt2",          invadpt2Rom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invadpt2,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"invaddlx",          invaddlxRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invadpt2,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"sinvzen",           sinvzenRom,     init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"sinvemag",          sinvemagRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"lrescue",           lrescueRom,     init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"galxwars",          galaxywarsRom,  init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"schaser",           schaserRom,     init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"spaceatt",          spaceattRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"spaceat2",          spaceattack2Rom,init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"invrvnge",          invrevengeRom,  init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"destinat",          destinatRom,    init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"laser",             laserRom,       init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  {"tester",            testerRom,      init_invaders,  start_invaders,  shutdown_invaders,  interrupt_invaders,  doin_invaders,  doout_invaders,  rdmem_invaders,  wrmem_invaders,  NMI_invaders, save_state_invaders, load_state_invaders, 256, 256, { 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0x40, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
};

void setup_driver(int x) {
        int i=x;
        machine_init(gameList[i].NMI);
//     exit_msg();printf("gns %d %s\r\n",i,gameList[i].gameName);exit_laser(99);
        driver->init = gameList[i].init;
        driver->start = gameList[i].start;
        driver->shutdown = gameList[i].shutdown;
        driver->doin = gameList[i].doin;
        driver->doout = gameList[i].doout;
        driver->rdmem = gameList[i].rdmem;
        driver->wrmem = gameList[i].wrmem;
        driver->interrupt = gameList[i].interrupt;
        driver->NMI = gameList[i].NMI;
        driver->save_state = gameList[i].save_state;
        driver->load_state = gameList[i].load_state;
}

void check_roms(int argc, char *argv[]) {
        tagRomList *selectedRom = NULL;
        int i,a=0,gameRomNum=0;

        sound_enable=0;
        msdos_set=0;

        for(i=0;i<LASER_TOTAL_SUPPORTED;i++) {
                if(strcmp(gameList[i].gameName,argv[1])==0) {
                        selectedRom = gameList[i].romList;
                        setup_driver(i);
                        gameRomNum=i;
                        a=1;
                        break;
                }
        }

        driver->gameSettings = gameList[gameRomNum].gameSettings;

        if (FindOption("-sound", 0, 0, 0, argc, argv)) {
                sound_enable=1;
        }

        if(a==0) {
                exit_msg();
                printf("Game not supported\r\n");
                exit_laser(99);
        }
        msdos_set=1;

        machine_gfx(gameList[gameRomNum].s_width, gameList[gameRomNum].s_height);

        if(driver->init(selectedRom) != 0) {
                exit_msg();
                printf("An error occured Initializing driver\r\n");
                exit_laser(99);
        }

}


