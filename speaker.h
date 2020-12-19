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
      m_on(false), 
      m_pin(pin),
      m_counter_trip(0), 
      m_counter(0), 
      m_note_finish_ms(0),
      m_beat_finish_ms(0),
      m_note_start_time_ms(0),
      m_frequency(frequency), 
      m_needs_note(true) {
    pinMode(m_pin, OUTPUT);
    digitalWrite(m_pin, 0);
  }

  void service(void);
  void play_note(Music::Note &note);
  bool needs_note();
  
private:
  volatile bool m_on;            ///< Keep track of our state, so we can flippy-flop
  size_t m_pin;                  ///< Speaker pin
  uint32_t m_counter_trip;       ///< Flip output here to simulate waves and trick your ears.
  volatile uint32_t m_counter;   ///< Counter for flipping
  uint32_t m_note_finish_ms;     ///< Time at which a *note* stops playing
  uint32_t m_beat_finish_ms;     ///< Time at which a beat stops playing (e.g. note + delay)
  uint32_t m_note_start_time_ms; ///< Time at which we started playing a note
  const uint32_t m_frequency;    ///< MUST MATCH ISR1 FREQUENCY
  volatile bool m_needs_note;    ///< If we've finished an entire beat period, signal we're in need of a note.
  
  static const uint8_t delay_ms = 15; ///< Delay between notes because real music takes time and blood and sweat.
};

// Poll this to see if you should send a new note.
bool IsrDrivenSpeaker::needs_note() {
  return m_needs_note;
}

// Checks our current tone, and flips the output if needed.
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
  
  // Do the flippy-flop
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
  m_note_finish_ms = m_note_start_time_ms + time_to_ms(note.duration);
  m_beat_finish_ms = m_note_finish_ms + delay_ms;
  m_needs_note = false;
}

} // Speaker
