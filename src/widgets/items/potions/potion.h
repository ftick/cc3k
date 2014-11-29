#ifndef __POTION_H__
#define __POTION_H__

#include "../item.h"

class Potion : public Item {
  public:
    Potion();
    virtual char to_char() const;
    virtual PlayerCharacter *use(PlayerCharacter* pc);
};

#endif
