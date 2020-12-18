#include "music.h"

constexpr size_t song_len = 98;
constexpr Music::Note song[song_len] PROGMEM {
  // Meas 1
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Half},
  // Meas 2
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Half},
  // Meas 3
  {Music::N_E4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_C4, Music::time::DottedQuarter},
  {Music::N_D4, Music::time::Eighth},
  // Meas 4
  {Music::N_E4, Music::time::Whole},
  // Meas 5
  {Music::N_F4, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_F4, Music::time::DottedQuarter},
  {Music::N_F4, Music::time::Eighth},
  // Meas 6
  {Music::N_F4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Eighth},
  {Music::N_E4, Music::time::Eighth},
  // Meas 7
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  // Meas 8
  {Music::N_D4, Music::time::Half},
  {Music::N_G4, Music::time::Half},
   // Meas 9
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Half},
  // Meas 10
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Half},
  // Meas 11
  {Music::N_E4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_C4, Music::time::DottedQuarter},
  {Music::N_D4, Music::time::Eighth},
  // Meas 12
  {Music::N_E4, Music::time::Whole},
  // Meas 13
  {Music::N_F4, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_F4, Music::time::DottedQuarter},
  {Music::N_F4, Music::time::Eighth},
  // Meas 14
  {Music::N_F4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_E4, Music::time::Eighth},
  {Music::N_E4, Music::time::Eighth},
  // Meas 15
  {Music::N_G4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  // Meas 16
  {Music::N_C4, Music::time::Whole},
    // Meas 17
  {Music::N_G3, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  {Music::N_C4, Music::time::Quarter},
  // Meas 18
  {Music::N_G3, Music::time::DottedHalf},
  {Music::N_G3, Music::time::Eighth},
  {Music::N_G3, Music::time::Eighth},
  //Meas 19
  {Music::N_G3, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter}, 
  {Music::N_D4, Music::time::Quarter},
  {Music::N_C4, Music::time::Quarter},
  // Meas 20
  {Music::N_A3, Music::time::Whole},
  // Meas 21
  {Music::N_G3, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  // Meas 22
  {Music::N_B3, Music::time::Whole},
  // Meas 23
  {Music::N_G4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  // Meas 24
  {Music::N_E4, Music::time::Whole},
  // Meas 25
  {Music::N_G3, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  {Music::N_C4, Music::time::Quarter},
  // Meas 26
  {Music::N_A3, Music::time::Whole},
  // Meas 27
  {Music::N_G3, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  {Music::N_C4, Music::time::Quarter},
  // Meas 28
  {Music::N_A3, Music::time::DottedHalf},
  {Music::N_A3, Music::time::Quarter},
  // Meas 29
  {Music::N_A3, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_E4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  // Meas 30
    {Music::N_G4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  // Meas 31
  {Music::N_A4, Music::time::Quarter},
  {Music::N_G4, Music::time::Quarter},
  {Music::N_F4, Music::time::Quarter},
  {Music::N_D4, Music::time::Quarter},
  // Meas 32
  {Music::N_C4, Music::time::Whole},
  //Rest
  {Music::N_REST, Music::time::Whole}
};
