#include "wound_def.h"

WoundDefBuff::WoundDefBuff(PlayerCharacter *pc) : Buff(pc) {}

int WoundDefBuff::get_def() {
  return component->get_def() - 5;
}
