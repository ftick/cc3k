#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "../widget.h"

class Character : public Widget {
  public:
    virtual bool move(direction_t dir);
    virtual void attack(Character &other);
    virtual bool defend(Character &other);
    virtual bool did_move();
    virtual void take_turn();
    virtual int  get_health();
    virtual void set_health();
    virtual int  get_atk();
    virtual void set_atk();
    virtual int  get_def();
    virtual void set_def();
    virtual int  get_gold();
    virtual void set_gold();
    bool is_alive();
};

#endif
