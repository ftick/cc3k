#ifndef __HOSTILE_H__
#define __HOSTILE_H__

#include "../character.h"

class Hostile : public Character {
  public:
    Hostile(int health = 25, int atk = 25, int def = 25);
    virtual void take_turn();
    virtual char to_char() const;
};

#endif
