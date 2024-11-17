#include "Sequencer.h"

const uint8_t seq_waltz_length = 12;
const uint8_t seq_waltz[seq_waltz_length * TRACKS_COUNT] = {
    // Rotated: 12x5
       0,   90,   37,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,   90,   37,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0
};


const uint8_t seq_tango_length = 32;
const uint8_t seq_tango[seq_tango_length * TRACKS_COUNT] = {
    // Rotated: 32x5
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,   47,    0,    0,    0,
       0,    0,    0,   90,    0,
       0,    0,    0,    0,  127,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0
};


const uint8_t seq_march_length = 32;
const uint8_t seq_march[seq_march_length * TRACKS_COUNT] = {
    // Rotated: 32x5
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
      90,    0,   37,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,  127,
      80,    0,   47,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  110,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,  120,
       0,    0,    0,  110,    0,
       0,    0,    0,   90,    0,
       0,    0,    0,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,  127,    0,
       0,    0,    0,   90,    0,
       0,  127,    0,    0,    0,
       0,   90,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0
};


const uint8_t seq_swing_length = 32;
const uint8_t seq_swing[seq_swing_length * TRACKS_COUNT] = {
       0,    0,  127,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0
};

const uint8_t seq_rock_length = 12;
const uint8_t seq_rock[seq_rock_length * TRACKS_COUNT] = {
       0,    0,  100,    0,    0,
       0,    0,  110,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,   80,   47,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
      80,    0,   47,    0,    0,
       0,    0,    0,    0,    0,
      80,    0,   47,    0,    0,
       0,    0,    0,    0,    0
};

const uint8_t seq_disco_length = 16;
const uint8_t seq_disco[seq_disco_length * TRACKS_COUNT] = {
     127,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
     127,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,  127,    0,    50,
       0,    0,    0,    0,    40,
       0,    0,    0,    0,    30,
       0,    0,    0,    0,    10
};

const uint8_t seq_bossa_length = 16;
const uint8_t seq_bossa[seq_bossa_length * TRACKS_COUNT] = {
      80,    0,   47,    0,    0,
       0,  127,  100,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
      80,    0,   47,    0,    0,
       0,    0,  127,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
      80,    0,   47,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
       0,    0,    0,    0,    0
};

const uint8_t seq_samba_length = 16;
const uint8_t seq_samba[seq_samba_length * TRACKS_COUNT] = {
       0,    0,    0,  127,    0,
      90,    0,   37,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0,
      90,    0,   37,    0,    0,
       0,    0,  127,    0,    0,
       0,    0,    0,    0,    0,
       0,  127,    0,    0,    0
};

const uint8_t* sequences[] = {
    seq_waltz,
    seq_tango,
    seq_march,
    seq_swing,
    seq_rock,
    seq_disco,
    seq_bossa,
    seq_samba
};

const uint8_t sequences_length[] = {
    seq_waltz_length,
    seq_tango_length,
    seq_march_length,
    seq_swing_length,
    seq_rock_length,
    seq_disco_length,
    seq_bossa_length,
    seq_samba_length
};

uint32_t sample_counter = 0;
uint32_t samples_per_step = 0;

const uint8_t* first_trigger = nullptr;
const uint8_t* last_trigger = nullptr;
const uint8_t* current_trigger = nullptr;

uint8_t track_state[] = {TRACK_STATE_ON, TRACK_STATE_ON, TRACK_STATE_ON, TRACK_STATE_ON, TRACK_STATE_ON};
