#include "boostatk.h"
#include "../../../buffs/boost_atk.h"
#include "../../../debug.h"

PlayerCharacter *BoostAtk::use(PlayerCharacter *pc) {
  return new BoostAtkBuff(Potion::use(pc));
}
