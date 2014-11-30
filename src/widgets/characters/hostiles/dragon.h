#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "hostile.h"
#include "../../items/gold/dragon_hoard.h"

class DragonHoard;

class Dragon : public Hostile {
    DragonHoard *hoard;
  public:
    Dragon(DragonHoard *hoard);
    char to_char() const;
    bool move(direction_t dir);
    void take_turn();
};

#endif
