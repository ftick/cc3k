#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__

#include "gold.h"
#include "../../characters/hostiles/dragon.h"
#include "../../../board/cell.h"

class Dragon;

class DragonHoard : public Gold {
    Dragon *dragon;
  public:
    DragonHoard(bool spawn=true);
    ~DragonHoard();
    PlayerCharacter *use(PlayerCharacter *pc);
    void set_pos(Cell *cell);
};

#endif
