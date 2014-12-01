#ifndef __BUFF_H__
#define __BUFF_H__

#include "../widgets/characters/player_characters/player_character.h"
#include "../widgets/characters/character.h"

class Buff : public PlayerCharacter {
  protected:
    PlayerCharacter *component;
  public:
    Buff(PlayerCharacter *pc);
    virtual ~Buff() = 0;
    virtual void set_pos(Cell *pos);
    virtual Cell *get_pos() const;
    virtual bool is_pathable(terrain_t t) const;
    virtual bool move(direction_t dir);
    virtual int  attack(Character &other);
    virtual int  attack(Merchant &other);
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
    virtual bool is_alive();
    virtual char to_char() const;
    virtual bool has_reached_stair() const;
    virtual bool attacks_merchants();
    virtual int  score();
    virtual void did_kill(Character &c);
    virtual std::string race();
};

#endif
