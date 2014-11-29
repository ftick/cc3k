#include "potion.h"
#include "../../../debug.h"

Potion::Potion() : Item() {}

char Potion::to_char() const {
  return 'P';
}

PlayerCharacter *Potion::use(PlayerCharacter *pc) {
  DEBUG("TODO (potions)");
  return pc;
}
