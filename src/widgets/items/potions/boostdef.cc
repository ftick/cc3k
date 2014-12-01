#include "boostdef.h"
#include "../../../buffs/boost_def.h"

PlayerCharacter *BoostDef::use(PlayerCharacter *pc) {
  return new BoostDefBuff(Potion::use(pc));
}
