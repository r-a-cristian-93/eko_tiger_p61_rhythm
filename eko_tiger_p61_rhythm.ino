#include "Sequencer.h"
#include "DrumMachine.h"
#include <Mozzi.h>
#include "stm32f4xx.h" 

// For STM32F411CEU6

__attribute((always_inline)) inline
bool areAllEqual8(const uint16_t* array) {
    return (array[0] == array[1]) &&
           (array[1] == array[2]) &&
           (array[2] == array[3]) &&
           (array[3] == array[4]) &&
           (array[4] == array[5]) &&
           (array[5] == array[6]) &&
           (array[6] == array[7]);
}

__attribute((always_inline)) inline
bool areAllEqual4(const uint16_t* array) {
    return (array[0] == array[1]) &&
           (array[1] == array[2]) &&
           (array[2] == array[3]);
}

// #if IS_STM32DUINO()
#   define LED_BUILTIN PC13
#   define MOZZI_AUDIO_PIN_1 PA8         // 32768Hz 3V pk-pk
#   define AIN_TEMPO_PIN PA7
#   define DIN_WALTZ  PB3
#   define DIN_TANGO  PB4
#   define DIN_MARCH  PB5
#   define DIN_SWING  PB6
#   define DIN_ROCK   PB7
#   define DIN_DISCO  PB8
#   define DIN_BOSSA  PB9
#   define DIN_SAMBA  PB10
#   define DIN_TO_BOOTLOADER   PA0
#   define DIN_PERC_KICK       PA1 
#   define DIN_PERC_KICK_HARD  PA2     
#   define DIN_PERC_SHAKER     PA3   
#   define DIN_PERC_SNARE      PA4 
#   define DIN_PERC_STICK      PA5 
// #endif

__attribute((always_inline)) inline
void handleIsAlive()
{
  static uint8_t led_on_ticks = 0;

  led_on_ticks++;

  if (led_on_ticks & (1 << 6))
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  }
}

void setup() {
  sequencer_init();
  sequencer_set_bpm(160);

  pinMode(DIN_TO_BOOTLOADER, INPUT_PULLUP);

  pinMode(AIN_TEMPO_PIN, INPUT_PULLUP);
  analogReadResolution(12);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(DIN_WALTZ, INPUT_PULLUP);
  pinMode(DIN_TANGO, INPUT_PULLUP);
  pinMode(DIN_MARCH, INPUT_PULLUP);
  pinMode(DIN_SWING, INPUT_PULLUP);
  pinMode(DIN_ROCK, INPUT_PULLUP);
  pinMode(DIN_DISCO, INPUT_PULLUP);
  pinMode(DIN_BOSSA, INPUT_PULLUP);
  pinMode(DIN_SAMBA, INPUT_PULLUP);

  pinMode(DIN_PERC_KICK, INPUT_PULLUP);
  pinMode(DIN_PERC_KICK_HARD, INPUT_PULLUP);
  pinMode(DIN_PERC_SHAKER, INPUT_PULLUP);
  pinMode(DIN_PERC_SNARE, INPUT_PULLUP);
  pinMode(DIN_PERC_STICK, INPUT_PULLUP);
  
  startMozzi(MOZZI_CONTROL_RATE);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
}

#define RHYTHM_BUTTONS_COUNT (8)
#define SAMPLES_COUNT (8)
#define RHYTHM_BUTTONS_MASK (0b11111111)

uint16_t rhythm_buttons_samples[SAMPLES_COUNT];
uint8_t rhythm_buttons_samples_counter;
uint8_t rhythm_buttons_state;

__attribute((always_inline)) inline
void handleRhythmButtons()
{
  rhythm_buttons_samples[rhythm_buttons_samples_counter] = (uint16_t)((GPIOB->IDR >> 3) & RHYTHM_BUTTONS_MASK);  //PB3 to PB10
  rhythm_buttons_samples_counter++;

  if (rhythm_buttons_samples_counter >= SAMPLES_COUNT)
  {
    rhythm_buttons_samples_counter = 0;
  }

  if (areAllEqual8(rhythm_buttons_samples) && (rhythm_buttons_samples[0] != rhythm_buttons_state))
  {
    rhythm_buttons_state = (uint8_t) rhythm_buttons_samples[0];

    for (uint8_t buttonIndex = 0; buttonIndex <= RHYTHM_BUTTONS_COUNT; buttonIndex++)
    {
			uint8_t buttonState = rhythm_buttons_state & (1 << buttonIndex);

      if (buttonState == LOW) // pressed
      {
        sequencer_set_sequence(buttonIndex);
        break;
      }
    }
  }
}

#define TRACK_BUTTONS_COUNT (5)
#define TRACK_BUTTONS_MASK (0b00011111)

uint16_t track_buttons_samples[SAMPLES_COUNT];
uint8_t track_buttons_samples_counter;
uint8_t track_buttons_state;

__attribute((always_inline)) inline
void handleTrackButtons()
{
  track_buttons_samples[track_buttons_samples_counter] = (uint16_t)((GPIOA->IDR >> 1) & TRACK_BUTTONS_MASK); //PA1 to PA5
  track_buttons_samples_counter++;

  if (track_buttons_samples_counter >= SAMPLES_COUNT)
  {
    track_buttons_samples_counter = 0;
  }

  if (areAllEqual8(track_buttons_samples) && (track_buttons_samples[0] != track_buttons_state))
  {
    track_buttons_state = track_buttons_samples[0];

    for (uint8_t trackIndex = 0; trackIndex <= TRACK_BUTTONS_COUNT; trackIndex++)
    {
      uint8_t trackState = track_buttons_state & (1 << trackIndex);

      sequencer_set_track_state(trackIndex, trackState);
    }
  }
}

#define TEMPO_SAMPLES_COUNT (4)
uint16_t tempo_control_samples[TEMPO_SAMPLES_COUNT] = {0};
uint8_t tempo_control_samples_counter = 0;
uint8_t tempo_control_state = 0;

__attribute((always_inline)) inline
void handleTempoControl()
{
  tempo_control_samples[tempo_control_samples_counter] = analogRead(AIN_TEMPO_PIN) >> 5;  // only 8 bits needed
  tempo_control_samples_counter++;

  if (tempo_control_samples_counter >= TEMPO_SAMPLES_COUNT)
  {
    tempo_control_samples_counter = 0;
  }

  if (areAllEqual4(tempo_control_samples) && tempo_control_samples[0] != tempo_control_state)
  {
    tempo_control_state = tempo_control_samples[0];

    sequencer_set_bpm((tempo_control_state << 1) + 0x3F);
  }
}

__attribute((always_inline)) inline
void handleJumpToBootloader() 
{
  if (!(GPIOA->IDR & (1 << 0)))
  {
    JumpToBootloader();
  }
}

void updateControl(){
  handleRhythmButtons();
  handleTrackButtons();
  handleTempoControl();

  handleIsAlive();
  handleJumpToBootloader();
}

AudioOutput_t updateAudio(){
  sequencer_tick();
	return MonoOutput::from16Bit(drum_machine_generate_sample() >> 3);
}

void loop(){
	audioHook();
}

void JumpToBootloader(void) {
    // De-initialize peripherals
    HAL_RCC_DeInit();
    HAL_DeInit();

    // Disable SysTick interrupt
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL = 0;

    // Set the MSP (Main Stack Pointer) to the value in the bootloader's vector table
    uint32_t sysMemAddr = 0x1FFF0000;
    __set_MSP(*(volatile uint32_t *)sysMemAddr);

    // Set the program counter to the bootloader's reset handler address
    void (*SysMemBootJump)(void) = (void (*)(void))(*(volatile uint32_t *)(sysMemAddr + 4));

    // Jump to the bootloader
    SysMemBootJump();
}