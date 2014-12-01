#include "woundatk.h"
#include "../../../buffs/wound_atk.h"

PlayerCharacter *WoundAtk::use(PlayerCharacter *pc) {
  return new WoundAtkBuff(Potion::use(pc));
}
