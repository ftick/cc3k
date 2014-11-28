#ifndef __PLAYER_CHARACTER_H__
#define __PLAYER_CHARACTER_H__

#include "../character.h"

class PlayerCharacter : public Character {
    bool at_stair;
  public:
    PlayerCharacter(int health, int max_health, int atk, int def);
    virtual void take_turn();
    char to_char() const;
    bool has_reached_stair() const;
    bool is_pathable(terrain_t t) const;
    bool move(direction_t dir);
};

#endif
