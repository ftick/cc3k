#ifndef __PLAYER_CHARACTER_H__
#define __PLAYER_CHARACTER_H__

#include "../character.h"

class PlayerCharacter : public Character {
  public:
    PlayerCharacter(int health, int max_health, int atk, int def);
};

#endif
