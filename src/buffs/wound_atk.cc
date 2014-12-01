#include "wound_atk.h"

WoundAtkBuff::WoundAtkBuff(PlayerCharacter *pc) : Buff(pc) {}

int WoundAtkBuff::get_atk() {
  return component->get_atk() - 5;
}
