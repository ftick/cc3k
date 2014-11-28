#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>

#include "cell.h"
#include "../widgets/widget.h"

class Widget;
class Cell;

class Chamber {
    std::vector<Cell*> cells;
  public:
    Chamber();
    void add_cell(Cell *c);
    void spawn(Widget *w);
    void make_stair();
};

#endif
