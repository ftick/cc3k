#ifndef __TROLL_H__
#define __TROLL_H__

#include "player_character.h"

class Troll : public PlayerCharacter {
  public:
    Troll();
    void take_turn();
    std::string race();
};

#endif
