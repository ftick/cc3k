#include "gold.h"

Gold::Gold(int amount) : Item(), amount(amount) {}

char Gold::to_char() const {
  return 'G';
}

PlayerCharacter *Gold::use(PlayerCharacter *pc) {
  pc->set_gold(pc->get_gold() + amount);
  get_pos()->set_widget(NULL);
  return pc;
}
