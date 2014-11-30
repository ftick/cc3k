#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../widget.h"

class Character : public Widget {
    int health;
    int max_health;
    int atk;
    int def;
    int gold;
    bool moved;

  public:
    Character(int health, int max_health, int atk, int def, int gold=0);
    virtual ~Character() = 0;
    virtual bool is_pathable(terrain_t t) const;
    virtual bool move(direction_t dir);
    virtual int  attack(Character &other);
    virtual int  defend(Character &other);
    virtual bool did_move();
    virtual void take_turn();
    virtual void reset();
    virtual int  get_health();
    virtual void set_health(int new_health);
    virtual int  get_atk();
    virtual void set_atk(int new_atk);
    virtual int  get_def();
    virtual void set_def(int new_def);
    virtual int  get_gold();
    virtual void set_gold(int new_gold);
    bool is_alive();
};

#endif
