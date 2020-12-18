#include <stdbool.h>

namespace Led {
  
class Led {
public:
  Led(size_t pin, uint8_t max_val = 255): m_pin(pin), m_curr_val(0), m_max_val(max_val) {
    // init by setting this pin as an output, and zero-ing it.
    pinMode(pin, OUTPUT);
    analogWrite(pin, m_curr_val);
  }

  void increase(uint8_t amount = 1);
  void decrease(uint8_t amount = 1);
  bool is_saturated(void);
  bool is_off(void);
  void turn_off(void);
  void turn_on(void);
  
  
private:
  size_t m_pin;
  uint16_t m_curr_val;
  const uint8_t m_max_val;
};

void Led::increase(uint8_t amount) {
  if ((m_max_val - m_curr_val) > amount) {
    m_curr_val = m_max_val;
    return;
  }
  m_curr_val += amount;
  analogWrite(m_pin, m_curr_val);
}

void Led::decrease(uint8_t amount) {
  if (m_curr_val < amount) {
    m_curr_val = 0;
  }
  m_curr_val -= amount;
  analogWrite(m_pin, m_curr_val);
}

bool Led::is_saturated(void) {
  return m_curr_val >= m_max_val;
}

bool Led::is_off() {
  return m_curr_val == 0;
}

void Led::turn_off(void) {
  m_curr_val = 0;
  analogWrite(m_pin, m_curr_val);
}

void Led::turn_on(void) {
  m_curr_val = m_max_val;
  analogWrite(m_pin, m_curr_val);
}
}// Led
