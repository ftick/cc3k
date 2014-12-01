#ifndef __PLAYER_CHARACTER_H__
#define __PLAYER_CHARACTER_H__

#include "../character.h"
#include "../hostiles/merchant.h"

class PlayerCharacter : public Character {
    bool merchant_attacker;
  public:
    PlayerCharacter(int health, int max_health, int atk, int def);
    virtual char to_char() const;
    virtual bool has_reached_stair() const;
    virtual bool is_pathable(terrain_t t) const;
    virtual bool move(direction_t dir);
    virtual bool attacks_merchants();
    virtual void take_turn();
    virtual int score();
    virtual int attack(Character &other);
    virtual int attack(Merchant &other);
    virtual void did_kill(Character &c);
    virtual std::string race() = 0;
};

#endif
