#include "music.h"

namespace Speaker{

/**
 * Representation of a speaker
 * Expects exclusive access to a pin
 * Also assumes the frequency at ctor time is matched with the ISR frequency where Speaker::service() is called.
 */
class IsrDrivenSpeaker {
public:
  IsrDrivenSpeaker(size_t pin, const uint32_t frequency) : 
      m_delay_ms(10U),
      m_on(false), 
      m_pin(pin),
      m_counter_trip(0), 
      m_counter(0), 
      m_note_finish_ms(0),
      m_beat_finish_ms(0),
      m_note_start_time_ms(0),
      m_frequency(frequency), 
      m_needs_note(true) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, 0);
  }

  void service(void);
  void play_note(Music::Note &note);
  bool needs_note();
  
private:
  uint32_t m_delay_ms;
  volatile bool m_on;
  size_t m_pin;
  uint32_t m_counter_trip;
  volatile uint32_t m_counter;
  uint32_t m_note_finish_ms;
  uint32_t m_beat_finish_ms;
  uint32_t m_note_start_time_ms;
  const uint32_t m_frequency; // MUST MATCH ISR1 FREQUENCY
  volatile bool m_needs_note;
  static const uint8_t delay_ms = 15;
};

bool IsrDrivenSpeaker::needs_note() {
  return m_needs_note;
}
// Checks our current tone, and flips the output if needed.
// TODO figure out a way to turn speaker off, preferably without extending ISR duration.
void IsrDrivenSpeaker::service() {

  // How long have we been playing this jazz?
  volatile uint32_t now = millis();

  // time for a new note
  if (now >= m_beat_finish_ms) {
    digitalWrite(m_pin, LOW);
    m_needs_note = true;
    return;
  }
  // otherwise time to just rest between notes
  else if (now >= m_note_finish_ms) {
    digitalWrite(m_pin, LOW);
    return;
  }
  
  // Do the flippy flip
  if (m_counter >= m_counter_trip) {
    if (m_on) {
      digitalWrite(m_pin, LOW);
    }
    else {
      digitalWrite(m_pin, HIGH);
    }
    m_on = !m_on;
    m_counter = 0;
  }
  ++m_counter;
}

// Play a Note!
void IsrDrivenSpeaker::play_note(Music::Note &note) {
  if (note.pitch == Music::N_REST) {
    digitalWrite(m_pin, LOW);
    m_counter_trip = UINT32_MAX;
  }
  else {
    m_counter_trip = m_frequency / note.pitch;
  }
  m_note_start_time_ms = millis();
  m_note_finish_ms = time_to_ms(note.duration) + m_note_start_time_ms;
  m_beat_finish_ms = m_note_finish_ms + delay_ms;
  m_needs_note = false;
}

} // Speaker
