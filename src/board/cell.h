#ifndef __CELL_H__
#define __CELL_H__

#include "text_display.h"

enum direction_t {
  NO,
  NE,
  EA,
  SE,
  SO,
  SW,
  WE,
  NW
};

enum terrain_t {
  V_WALL,
  H_WALL,
  TILE,
  DOOR,
  PATHWAY
};

class Cell {
  public:
    Cell(int row, int col, TextDisplay *display, terrain_t terrain);
    void add_neighbour(direction_t dir, Cell *neighbour);
};

#endif
