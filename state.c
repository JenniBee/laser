#include "laser.h"

int save_state(state* save, int ram_size) {
        FILE *fd;

        fd = fopen("laser.sav", "wb");
        if(!fd) {
                return(1);
        }
        fwrite(&save->stateRAM, ram_size, 1, fd);
        fwrite(&save->z80R, sizeof(reg), 1, fd);
        fwrite(&save->m6502R, sizeof(M6502), 1, fd);
        fclose(fd);

        return(0);
}

state *load_state(int ram_size) {
        state *loadstate;
        FILE *fd;
        fd = fopen("laser.sav", "rb");
        if(!fd) {
                return NULL;
        }

        fread(&loadstate->stateRAM, ram_size, 1, fd);
        fread(&loadstate->z80R, sizeof(reg), 1, fd);
        fread(&loadstate->m6502R, sizeof(M6502), 1, fd);
        fclose(fd);

        return(loadstate);
}

