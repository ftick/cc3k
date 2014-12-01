#ifndef __SHADE_H__
#define __SHADE_H__

#include "player_character.h"

class Shade : public PlayerCharacter {
  public:
    Shade();
    int score();
    std::string race();
};

#endif
