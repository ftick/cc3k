#ifndef __POISONHEALTH_H__
#define __POISONHEALTH_H__

#include "potion.h"

class PoisonHealth : public Potion {
  public:
    PoisonHealth();
    PlayerCharacter *use(PlayerCharacter* pc);
};

#endif
