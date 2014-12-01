#ifndef __WOUND_DEF_H__
#define __WOUND_DEF_H__

#include "buff.h"

class WoundDefBuff : public Buff {
  public:
    WoundDefBuff(PlayerCharacter *pc);
    virtual int get_def();
};

#endif
