namespace Servo {

// Experimentally determined
// Maybe invest in Servos that cost more than $1.80
constexpr float c_zero_duty = 0.05;
constexpr float c_scalar_duty = 0.13;

/**
 * An ISR Driven Servo
 * Hand it a pin and an interrupt frequency, and it
 * figures out everything else.
 */
class IsrDrivenServo {
public:
  IsrDrivenServo(size_t pin, const uint32_t frequency) : 
    m_pin(pin), 
    m_counter(UINT32_MAX),
    isr_period(frequency / (cmd_frequency)),
    toggle(0) {
      pinMode(m_pin, OUTPUT);
    }


  void service(void);
  void command(uint8_t angle);
  void zero();
  
private:
  static constexpr uint8_t max_angle = 240;     ///< trash servo!
  static constexpr uint16_t cmd_frequency = 25; ///< command at 50Hz (25 * 2)
  const size_t m_pin;                           ///< pin attached to servo input
  uint32_t m_counter;                           ///< ISR counter.
  const uint32_t isr_period;                    ///< Calculated length of our cmd_frequency period, in ISR's
  uint32_t toggle;                              ///< counter increments before we flip output
};

/**
 * This is called from the interrupt and determines what (if anything) our serveo needs to do.
 */
void IsrDrivenServo::service(void) {
  if (m_counter == UINT32_MAX) {
    return;
  }

  // do the thing
  m_counter++;
  if (m_counter < toggle) {
    digitalWrite(m_pin, HIGH);
    return;
  }
  if (m_counter >= toggle) {
    digitalWrite(m_pin, LOW);
  }
  if (m_counter >= isr_period) {
    m_counter = 0;
  }
}

/**
 * Command servo to an angle.
 * Cheapo servo has no feedback. Dunno where it is.
 * Hopefully somewhere.
 */
void IsrDrivenServo::command(uint8_t angle) {
  float duty = 0.0;
  if (angle > max_angle) {
    duty = c_zero_duty + c_scalar_duty;
  } else {
    duty = c_zero_duty + c_scalar_duty * (static_cast<float>(angle) / static_cast<float>(max_angle));
  }
  toggle = duty * isr_period;
  m_counter = 0;
}

// Convenience for zero'ing servo.
void IsrDrivenServo::zero() {
  command(0);
}

} // namespace Servo
