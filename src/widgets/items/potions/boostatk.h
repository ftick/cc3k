#ifndef __BOOSTATK_H__
#define __BOOSTATK_H__

#include "potion.h"

class BoostAtk : public Potion {
  public:
    PlayerCharacter *use(PlayerCharacter *pc);
};

#endif
