#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "../hostiles/dwarf.h"
#include "player_character.h"

class Vampire : public PlayerCharacter {
  public:
    Vampire();
    int attack(Character &other);
    int attack(Dwarf &other);
    std::string race();
};

#endif
