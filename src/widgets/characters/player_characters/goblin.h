#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "player_character.h"

class Goblin : public PlayerCharacter {
  public:
    Goblin();
    void did_kill(Character &other);
    std::string race();
};

#endif
