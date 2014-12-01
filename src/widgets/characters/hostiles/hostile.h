#ifndef __HOSTILE_H__
#define __HOSTILE_H__

#include "../character.h"

class Hostile : public Character {
  public:
    Hostile(int health = 25, int atk = 25, int def = 25, int gold = -1);
    virtual void take_turn();
    virtual int  attack(Character &other);
    virtual char to_char() const;
};

#endif
