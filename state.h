#ifndef _STATE_H_
#define _STATE_H_

typedef struct {
        byte *stateRAM;
        reg z80R; //z80
        M6502 *m6502R; //m6502
} state;

int save_state(state* save, int ram_size);
state *load_state(int ram_size);

#endif /* _STATE_H_ */
