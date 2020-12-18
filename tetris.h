#include "music.h"

using Music::time::Quarter;
using Music::time::Half;
using Music::time::Eighth;
using Music::time::Whole;
using Music::time::DottedQuarter;

using namespace Music;

constexpr size_t song_len = 99;
constexpr Music::Note song[song_len] PROGMEM {
  // Meas 1
  {N_E5, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_C5, Eighth},
  {N_B4, Eighth},
  // Meas 2
  {N_A4, Quarter},
  {N_A4, Eighth},
  {N_C5, Eighth},
  {N_E5, Quarter},
  {N_D5, Eighth},
  {N_C5, Eighth},
  // Meas 3
  {N_B4, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_E5, Quarter},
  // Meas 4
  {N_C5, Quarter},
  {N_A4, Quarter},
  {N_A4, Quarter},
  {N_REST, Quarter},
  // Meas 5
  {N_REST, Eighth},
  {N_D5, Quarter},
  {N_F5, Eighth},
  {N_A5, Quarter},
  {N_G5, Eighth},
  {N_F5, Eighth},
  // Meas 6
  {N_E5, DottedQuarter},
  {N_C5, Eighth},
  {N_E5, Quarter},
  {N_D5, Eighth},
  {N_C5, Eighth},
  // Meas 7
  {N_B4, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_E5, Quarter},
  // Meas 8
  {N_C5, Quarter},
  {N_A4, Quarter},
  {N_A4, Quarter},
  {N_REST, Quarter},
  // Mea 9
  {N_E4, Half},
  {N_C4, Half},
  // Meas 10
  {N_D4, Half},
  {N_B3, Half},
  // Meas 11
  {N_C4, Half},
  {N_A3, Half},
  // Meas 12
  {N_GS3, Half},
  {N_B3, Half},
  // Meas 13
  {N_E4, Half},
  {N_C4, Half},
  // Meas 14
  {N_D4, Half},
  {N_B3, Half},
  // Meas 15
  {N_C4, Quarter},
  {N_E4, Quarter},
  {N_A4, Quarter},
  {N_A4, Quarter},
  // Meas 16
  {N_GS4, Whole},
  // Meas 17
  {N_E5, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_C5, Eighth},
  {N_B4, Eighth},
  // Meas 18
  {N_A4, Quarter},
  {N_A4, Eighth},
  {N_C5, Eighth},
  {N_E5, Quarter},
  {N_D5, Eighth},
  {N_C5, Eighth},
  // Meas 19
  {N_B4, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_E5, Quarter},
  // Meas 20
  {N_C5, Quarter},
  {N_A4, Quarter},
  {N_A4, Quarter},
  {N_REST, Quarter},
  // Meas 21
  {N_REST, Eighth},
  {N_D5, Quarter},
  {N_F5, Quarter},
  {N_A5, Quarter},
  {N_G5, Eighth},
  {N_F5, Eighth},
  // Meas 22
  {N_E5, DottedQuarter},
  {N_C5, Eighth},
  {N_E5, Eighth},
  {N_D5, Eighth},
  {N_C5, Eighth},
  // Meas 23
  {N_B4, Quarter},
  {N_B4, Eighth},
  {N_C5, Eighth},
  {N_D5, Quarter},
  {N_E5, Quarter},
  // Meas 25
  {N_C5, Quarter},
  {N_A4, Quarter},
  {N_A4, Quarter}, 
  // Meas 
  {N_REST,Whole}
};
