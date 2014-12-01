#ifndef __BOOST_ATK_H__
#define __BOOST_ATK_H__

#include "buff.h"

class BoostAtkBuff : public Buff {
  public:
    BoostAtkBuff(PlayerCharacter *pc);
    virtual int get_atk();
};

#endif
