#ifndef __BOOST_DEF_H__
#define __BOOST_DEF_H__

#include "buff.h"

class BoostDefBuff : public Buff {
  public:
    BoostDefBuff(PlayerCharacter *pc);
    virtual int get_def();
};

#endif
