#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>

#include "text_display.h"
#include "chamber.h"
#include "terrain_t.h"
#include "direction_t.h"
#include "../widgets/widget.h"

class Chamber;
class Widget;
class PlayerCharacter;

class Cell {
    int row;
    int col;
    TextDisplay *display;
    terrain_t terrain;
    std::map<direction_t, Cell*> neighbours;
    Widget *widget;
    Chamber *chamber;

  public:
    Cell(int row, int col, TextDisplay *display, terrain_t terrain);
    terrain_t get_terrain();
    void set_terrain(terrain_t t);
    Chamber *get_chamber();
    void set_chamber(Chamber *c);
    void add_neighbour(direction_t dir, Cell *neighbour);
    Cell *get_neighbour(direction_t dir);
    direction_t get_unoccupied_direction();
    Cell *get_unoccupied_tile_neighbour();
    PlayerCharacter *get_adjacent_player_character();
    void set_widget(Widget *w);
    Widget *get_widget();
    friend std::ostream &operator<<(std::ostream &out, Cell &cell);
};

#endif
