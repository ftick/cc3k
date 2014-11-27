#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>

#include "text_display.h"
#include "../widgets/widget.h"

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

std::ostream &operator<<(std::ostream &out, terrain_t terrain);

class Widget;

class Cell {
    int row;
    int col;
    TextDisplay *display;
    terrain_t terrain;
    std::map<direction_t, Cell*> neighbours;
    Widget *widget;

  public:
    Cell(int row, int col, TextDisplay *display, terrain_t terrain);
    void add_neighbour(direction_t dir, Cell *neighbour);
    void get_neighbour(direction_t dir);
    void set_widget();
    Widget *get_widget();
    friend std::ostream &operator<<(std::ostream &out, Cell &cell);
};

#endif
