#ifndef SEQUENCER_H
#define SEQUENCER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "DrumMachine.h"

#define TRACKS_COUNT (5)
#define SEQUENCES_COUNT (8)
#ifndef SAMPLE_RATE
#define SAMPLE_RATE (32768.0)
#endif
#define TRACK_STATE_ON (1)
#define TRACK_STATE_OFF (0)

extern const uint8_t* sequences[];
extern const uint8_t sequences_length[];
extern uint32_t sample_counter;
extern uint32_t samples_per_step;

extern const uint8_t* first_trigger;
extern const uint8_t* last_trigger;
extern const uint8_t* current_trigger;

extern uint8_t track_state[];

// inline
void sequencer_set_bpm(uint32_t bpm);
void sequencer_set_sequence(uint8_t sequenceNumber);
void sequencer_set_track_state(uint8_t trackNumber, uint8_t trackState);

__attribute__((always_inline)) inline
void sequencer_init()
{
    sample_counter = 0;
    sequencer_set_sequence(0);
    sequencer_set_bpm(160);
}

__attribute__((always_inline)) inline
void sequencer_set_bpm(uint32_t bpm)
{
    // Assuming 16th notes
    samples_per_step = (60.0 * SAMPLE_RATE) / (bpm * 4.0);
}

__attribute__((always_inline)) inline
void sequencer_set_sequence(uint8_t sequenceNumber)
{
    if (sequenceNumber < SEQUENCES_COUNT)
    {
        first_trigger = sequences[sequenceNumber];
        last_trigger = first_trigger + sequences_length[sequenceNumber] * TRACKS_COUNT;
        current_trigger = first_trigger;
    }
}

__attribute__((always_inline)) inline
void sequencer_tick()
{
    sample_counter++;

    if (sample_counter < samples_per_step)
    {
        return;
    }

    sample_counter = 0;

    for (int trackNumber = 0; trackNumber < TRACKS_COUNT; ++trackNumber)
    {
        int current_velocity = *(current_trigger++);

        if (current_velocity > 0 && track_state[trackNumber])
        {
            drum_machine_play(trackNumber, current_velocity);
        }
    }

    // Wrapping around based on the number of steps in the sequence
    if (current_trigger == last_trigger)
    {
        current_trigger = first_trigger;
    }
}

__attribute__((always_inline)) inline
void sequencer_set_track_state(uint8_t trackNumber, uint8_t trackState) {
    track_state[trackNumber] = trackState;
}

#ifdef __cplusplus
}
#endif

#endif
