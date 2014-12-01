#include "merchant.h"
#include "../player_characters/player_character.h"
#include "../../items/gold/gold.h"

Merchant::Merchant() : Hostile(30, 70, 5, MERCHANT_HOARD) {}

char Merchant::to_char() const {
  return 'M';
}

void Merchant::take_turn() {
  if (PlayerCharacter *pc = get_pos()->get_adjacent_player_character()) {
    if (pc->attacks_merchants()) {
      Hostile::take_turn();
    }
  } else {
    Hostile::take_turn();
  }
}
