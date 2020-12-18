#pragma once

namespace Music {
  
typedef enum time : uint8_t {
  Rest = 0,
  Eighth = 1,
  Quarter = 2,
  DottedQuarter = 3,
  Half = 4,
  DottedHalf = 5,
  Whole = 6,
}time;

uint32_t time_to_ms(time t) {
  uint32_t delay_time = 0;
  switch (t) {
    case time::Rest:
      delay_time = 50;
      break;
    case time::Eighth:
      delay_time = 125;
      break;
    case time::Quarter:
      delay_time = 250;
      break;
    case time::DottedQuarter:
      delay_time = 375;
      break;
    case time::Half:
      delay_time = 500;
      break;
    case time::DottedHalf:
      delay_time = 750;
      break;
    case time::Whole:
      delay_time = 1000;
      break;
    default:
      delay_time = 5000;
      break;
  }
  return delay_time;
}

// Assumes 4/4
typedef struct Note{
  float pitch;
  time duration;

  constexpr Note() : pitch(0.0), duration(time::Rest) {}
  constexpr Note(float pit, Music::time dur) : pitch(pit), duration(dur) {}

}Note;

// TODO B0 and B1 conflict with the arduino defs despite being namespaced... remove N_ portion
constexpr float N_REST = 0.0;
constexpr float N_C0 = 16.35;
constexpr float N_CS0 = 17.32;
constexpr float N_D0 = 18.35;
constexpr float N_DS0 = 19.45;
constexpr float N_E0 = 20.60;
constexpr float N_F0 = 21.83;
constexpr float N_FS0 = 23.12;
constexpr float N_G0 = 24.50;
constexpr float N_GS0 = 25.96;
constexpr float N_A0 = 27.50;
constexpr float N_AS0 = 29.14;
constexpr float N_B0 = 30.87;
constexpr float N_C1 = 32.70;
constexpr float N_CS1 = 34.65;
constexpr float N_D1 = 36.71;
constexpr float N_DS1 = 38.89;
constexpr float N_E1 = 41.20;
constexpr float N_F1 = 43.65;
constexpr float N_FS1 = 46.25;
constexpr float N_G1 = 49.00;
constexpr float N_GS1 = 51.91;
constexpr float N_A1 = 55.00;
constexpr float N_AS1 = 58.27;
constexpr float N_B1 = 61.74;
constexpr float N_C2 = 65.41;
constexpr float N_CS2 = 69.30;
constexpr float N_D2 = 73.42;
constexpr float N_DS2 = 77.78;
constexpr float N_E2 = 82.41;
constexpr float N_F2 = 87.31;
constexpr float N_FS2 = 92.50;
constexpr float N_G2 = 98.00;
constexpr float N_GS2 = 103.83;
constexpr float N_A2 = 110.00;
constexpr float N_AS2 = 116.54;
constexpr float N_B2 = 123.47;
constexpr float N_C3 = 130.81;
constexpr float N_CS3 = 138.59;
constexpr float N_D3 = 146.83;
constexpr float N_DS3 = 155.56;
constexpr float N_E3 = 164.81;
constexpr float N_F3 = 174.61;
constexpr float N_FS3 = 185.00;
constexpr float N_G3 = 196.00;
constexpr float N_GS3 = 207.65;
constexpr float N_A3 = 220.00;
constexpr float N_AS3 = 233.08;
constexpr float N_B3 = 246.94;
constexpr float N_C4 = 261.63;
constexpr float N_CS4 = 277.18;
constexpr float N_D4 = 293.66;
constexpr float N_DS4 = 311.13;
constexpr float N_E4 = 329.63;
constexpr float N_F4 = 349.23;
constexpr float N_FS4 = 369.99;
constexpr float N_G4 = 392.00;
constexpr float N_GS4 = 415.30;
constexpr float N_A4 = 440.00;
constexpr float N_AS4 = 466.16;
constexpr float N_B4 = 493.88;
constexpr float N_C5 = 523.25;
constexpr float N_CS5 = 554.37;
constexpr float N_D5 = 587.33;
constexpr float N_DS5 = 622.25;
constexpr float N_E5 = 659.25;
constexpr float N_F5 = 698.46;
constexpr float N_FS5 = 739.99;
constexpr float N_G5 = 783.99;
constexpr float N_GS5 = 830.61;
constexpr float N_A5 = 880.00;
constexpr float N_AS5 = 932.33;
constexpr float N_B5 = 987.77;
constexpr float N_C6 = 1046.50;
constexpr float N_CS6 = 1108.73;
constexpr float N_D6 = 1174.66;
constexpr float N_DS6 = 1244.51;
constexpr float N_E6 = 1318.51;
constexpr float N_F6 = 1396.91;
constexpr float N_FS6 = 1479.98;
constexpr float N_G6 = 1567.98;
constexpr float N_GS6 = 1661.22;
constexpr float N_A6 = 1760.00;
constexpr float N_AS6 = 1864.66;
constexpr float N_B6 = 1975.53;
constexpr float N_C7 = 2093.00;
constexpr float N_CS7 = 2217.46;
constexpr float N_D7 = 2349.32;
constexpr float N_DS7 = 2489.02;
constexpr float N_E7 = 2637.02;
constexpr float N_F7 = 2793.83;
constexpr float N_FS7 = 2959.96;
constexpr float N_G7 = 3135.96;
constexpr float N_GS7 = 3322.44;
constexpr float N_A7 = 3520.00;
constexpr float N_AS7 = 3729.31;
constexpr float N_B7 = 3951.07;
constexpr float N_C8 = 4186.01;
constexpr float N_CS8 = 4434.92;
constexpr float N_D8 = 4698.63;
constexpr float N_DS8 = 4978.03;
constexpr float N_E8 = 5274.04;
constexpr float N_F8 = 5587.65;
constexpr float N_FS8 = 5919.91;
constexpr float N_G8 = 6271.93;
constexpr float N_GS8 = 6644.88;
constexpr float N_A8 = 7040.00;
constexpr float N_AS8 = 7458.62;
constexpr float N_B8 = 7902.13;


} //Music
