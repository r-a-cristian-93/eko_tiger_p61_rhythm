#include "DrumMachine.h"
#include "perc_kick.h"
#include "perc_kick_hard.h"
#include "perc_shaker.h"
#include "perc_snare.h"
#include "perc_stick.h"

DrumInstrument instrument[INSTRUMENTS_COUNT] = {
    {wav_perc_kick, wav_perc_kick_length,             0, false, 0},
    {wav_perc_kick_hard, wav_perc_kick_hard_length,   0, false, 0},
    {wav_perc_shaker, wav_perc_shaker_length,         0, false, 0},
    {wav_perc_snare, wav_perc_snare_length,           0, false, 0},
    {wav_perc_stick, wav_perc_stick_length,           0, false, 0}
};