#include "dragon.h"

Dragon::Dragon(DragonHoard *hoard) : Hostile(150, 20, 20), hoard(hoard) {}

char Dragon::to_char() const {
  return 'D';
}

bool Dragon::move(direction_t dir) {
  return true;
}

void Dragon::take_turn() {
  Hostile::take_turn();
  if (!get_pos()->get_adjacent_player_character()) {
    if (PlayerCharacter *pc = hoard->get_pos()->get_adjacent_player_character()) {
      attack(*pc);
    }
  }
}
