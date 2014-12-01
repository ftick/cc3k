#include "poisonhealth.h"

PoisonHealth::PoisonHealth() : Potion() {}

PlayerCharacter *PoisonHealth::use(PlayerCharacter *pc) {
  pc->set_health(pc->get_health() - 10);
  return Potion::use(pc);
}
