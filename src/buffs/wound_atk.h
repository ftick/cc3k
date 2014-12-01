#ifndef __WOUND_ATK_H__
#define __WOUND_ATK_H__

#include "buff.h"

class WoundAtkBuff : public Buff {
  public:
    WoundAtkBuff(PlayerCharacter *pc);
    virtual int get_atk();
};

#endif
