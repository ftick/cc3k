#include "restorehealth.h"

RestoreHealth::RestoreHealth() : Potion() {}

PlayerCharacter *RestoreHealth::use(PlayerCharacter *pc) {
  pc->set_health(pc->get_health() + 10);
  return pc;
}
