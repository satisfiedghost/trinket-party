#include "led.h"
#include "speaker.h"
#include "music.h"
#include "interrupt.h"
#include "tetris.h"

#include <stdbool.h>

// Program Constants
constexpr size_t RED_LED_PIN = 0;
constexpr size_t GREEN_LED_PIN = 1;
constexpr size_t SPEAKER_PIN = 2;
constexpr size_t BLUE_LED_PIN = 4;

// Drivers
Speaker::IsrDrivenSpeaker speaker(SPEAKER_PIN, g_isr1_frequency);
Led::Led red_led(RED_LED_PIN);
Led::Led green_led(GREEN_LED_PIN);
// OCR1C_cmp_count is the max because we mucked with timer1
Led::Led blue_led(BLUE_LED_PIN, OCR1C_cmp_count);

// Globals
size_t song_idx = 0;
size_t led_idx = 0;
Music::Note note;
Led::Led all_leds[3] = {red_led, green_led, blue_led };

void setup() {
  Interrupt::configure_isr1();
}


void loop() { 
  if (speaker.needs_note()) {
    note = Music::Note(pgm_read_float(&song[song_idx]), static_cast<Music::time>(pgm_read_byte(&song[song_idx].duration)));
    speaker.play_note(note);
    song_idx = (song_idx + 1) % song_len;

    all_leds[led_idx].turn_off();
    led_idx = (led_idx + 1) % 3;
    all_leds[led_idx].turn_on();
  }
}    

// occurs at 10khz
ISR(TIMER1_COMPA_vect){
  speaker.service();
}
