#include "hostile.h"
#include "../../items/gold/gold.h"
#include "../player_characters/player_character.h"
#include "../../../debug.h"
#include <climits>
#include <cstdlib>

Hostile::Hostile(int health, int atk, int def) :
    Character(health, INT_MAX, atk, def) {
  set_gold((rand() % 2) ? SMALL_GOLD_PILE : NORMAL_GOLD_PILE);
}

void Hostile::take_turn() {
  if (PlayerCharacter *pc = get_pos()->get_adjacent_player_character()) {
    attack(*pc);
  } else {
    direction_t move_to = get_pos()->get_unoccupied_direction();
    if (move_to != -1) {
      move(move_to);
    }
  }
}

int Hostile::attack(Character &other) {
  int hit = rand() % 2;
  if (hit) {
    return Character::attack(other);
  } else {
    return -1;
  }
}

char Hostile::to_char() const {
  return '?';
}
