#include "potion.h"
#include "../../../debug.h"

Potion::Potion() : Item() {}

char Potion::to_char() const {
  return 'P';
}

PlayerCharacter *Potion::use(PlayerCharacter *pc) {
  get_pos()->set_widget(NULL);
  return pc;
}
