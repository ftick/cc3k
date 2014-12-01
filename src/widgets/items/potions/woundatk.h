#ifndef __WOUNDATK_H__
#define __WOUNDATK_H__

#include "potion.h"

class WoundAtk : public Potion {
  public:
    PlayerCharacter *use(PlayerCharacter *pc);
};

#endif
