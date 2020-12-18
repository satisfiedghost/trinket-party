constexpr uint32_t g_isr1_frequency = 18E3;
constexpr uint32_t MM = 1E6;
constexpr uint8_t OCR1C_cmp_count = MM/ g_isr1_frequency;

namespace Interrupt {
  void configure_isr1() {  
    TCCR1 |= (1 << CTC1);    //> clear timer on compare match
    OCR1C = OCR1C_cmp_count; //> compare match value
    TIMSK |= (1 << OCIE1A);  //> enable compare match interrupt
  }
}
