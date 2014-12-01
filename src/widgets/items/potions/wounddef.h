#ifndef __WOUNDDEF_H__
#define __WOUNDDEF_H__

#include "potion.h"

class WoundDef : public Potion {
  public:
    PlayerCharacter *use(PlayerCharacter *pc);
};

#endif
