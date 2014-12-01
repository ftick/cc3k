#include "wounddef.h"
#include "../../../buffs/wound_def.h"

PlayerCharacter *WoundDef::use(PlayerCharacter *pc) {
  return new WoundDefBuff(Potion::use(pc));
}
