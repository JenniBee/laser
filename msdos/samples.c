#include "laser.h"

int init_sound() {
        return(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0));
}

void shutdown_sound() {
        remove_sound();
}
