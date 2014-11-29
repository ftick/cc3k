#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>

#include "cell.h"
#include "chamber.h"
#include "text_display.h"
#include "../widgets/characters/player_characters/player_character.h"
#include "../widgets/characters/hostiles/hostile.h"
#include "../widgets/items/potions/potion.h"
#include "../widgets/items/gold/gold.h"

class Floor {
    TextDisplay *display;
    Cell ***grid;

    std::vector<Chamber*> chambers;
    std::vector<Hostile*> hostiles;
    std::vector<Potion*>  potions;
    std::vector<Gold*>    gold;

    void random_chamber_spawn(Widget * w);

  public:
    Floor(TextDisplay *display);
    ~Floor();

    void generate(PlayerCharacter *pc);

    friend std::istream &operator>>(std::istream &in, Floor &floor);
    friend std::ostream &operator<<(std::ostream &out, Floor &floor);
};

#endif
