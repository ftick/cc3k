#ifndef __GOLD_H__
#define __GOLD_H__

#include "../item.h"

enum GOLD_AMOUNT {
  DRAGON_HOARD     = 6,
  MERCHANT_HOARD   = 4,
  NORMAL_GOLD_PILE = 2,
  SMALL_GOLD_PILE  = 1
};

class Gold : public Item {
    int amount;
  public:
    Gold(int amount);
    char to_char() const;
    PlayerCharacter *use(PlayerCharacter *pc);
};

#endif
