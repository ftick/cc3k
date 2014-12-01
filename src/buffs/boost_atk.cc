#include "boost_atk.h"
#include "../debug.h"

BoostAtkBuff::BoostAtkBuff(PlayerCharacter *pc) : Buff(pc) {}

int BoostAtkBuff::get_atk() {
  return component->get_atk() + 5;
}
