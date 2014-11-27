#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>

#include "cell.h"
#include "chamber.h"
#include "text_display.h"

class Floor {
    Chamber *chamber[5];
    TextDisplay *display;
    Cell ***grid;

    //std::vector<Hostile*>;
    //std::vector<Potion*>;
    //std::vector<Gold*>;

  public:
    Floor(TextDisplay *display);
    Floor(const Floor &floor);
    ~Floor();

    void generate();

    friend std::istream &operator>>(std::istream &in, Floor &floor);
    friend std::ostream &operator<<(std::ostream &out, Floor &floor);
};

#endif
