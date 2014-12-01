#ifndef __BOOSTDEF_H__
#define __BOOSTDEF_H__

#include "potion.h"

class BoostDef : public Potion {
  public:
    PlayerCharacter *use(PlayerCharacter *pc);
};

#endif
