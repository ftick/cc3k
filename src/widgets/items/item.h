#ifndef __ITEM_H__
#define __ITEM_H__

#include "../widget.h"
#include "../characters/player_characters/player_character.h"

class Item : public Widget {
  public:
    Item();
    virtual ~Item() = 0;

    virtual PlayerCharacter *use(PlayerCharacter* pc) = 0;
};

#endif
