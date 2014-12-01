#include "boost_def.h"

BoostDefBuff::BoostDefBuff(PlayerCharacter *pc) : Buff(pc) {}

int BoostDefBuff::get_def() {
  return component->get_def() + 5;
}
