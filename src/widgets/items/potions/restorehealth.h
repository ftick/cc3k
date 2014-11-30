#ifndef __RESTOREHEALTH_H__
#define __RESTOREHEALTH_H__

#include "potion.h"

class RestoreHealth : public Potion {
  public:
    RestoreHealth();
    PlayerCharacter *use(PlayerCharacter* pc);
};

#endif
