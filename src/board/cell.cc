#include "cell.h"
#include "../debug.h"
#include "../widgets/characters/player_characters/player_character.h"
#include <cstdlib>

Cell::Cell(int row, int col, TextDisplay *display, terrain_t terrain) : row(row), col(col), display(display), terrain(terrain), widget(NULL), chamber(NULL) {}

terrain_t Cell::get_terrain() {
  return terrain;
}

void Cell::set_terrain(terrain_t t) {
  terrain = t;
}

Chamber* Cell::get_chamber() {
  return chamber;
}

void Cell::set_chamber(Chamber *c) {
  if ((terrain != TILE) || chamber) return;

  //DEBUG("Setting cell (" << row << ", " << col << ") to " << c);

  chamber = c;
  c->add_cell(this);

  for (std::map<direction_t, Cell*>::iterator it = neighbours.begin(); it != neighbours.end(); ++it) {
    it->second->set_chamber(c);
  }
}

void Cell::add_neighbour(direction_t dir, Cell* neighbour) {
  neighbours[dir] = neighbour;
}

Cell *Cell::get_neighbour(direction_t dir) {
  return neighbours[dir];
}

direction_t Cell::get_unoccupied_direction() {
  int dir  = rand() % 8;
  int orig = dir;

  while (!neighbours[static_cast<direction_t>(dir)] ||
         neighbours[static_cast<direction_t>(dir)]->get_terrain() != TILE ||
         neighbours[static_cast<direction_t>(dir)]->get_widget()) {
    dir = (dir + 1) % 8;
    if (dir == orig) {
      DEBUG("Unoccupied tile neighbour not found!");
      return static_cast<direction_t>(-1);
    }
  }
  
  return static_cast<direction_t>(dir);
}

Cell *Cell::get_unoccupied_tile_neighbour() {
  direction_t dir = get_unoccupied_direction();
  return dir == -1 ? NULL : neighbours[dir];
}

void Cell::set_widget(Widget *w) {
  widget = w;
}

Widget *Cell::get_widget() {
  return widget;
}

PlayerCharacter *Cell::get_adjacent_player_character() {
  for (int dir = NO; dir <= NW; ++dir) {
    Cell *c = get_neighbour(static_cast<direction_t>(dir));
    if (c && c->get_widget()) {
      if (PlayerCharacter *pc = dynamic_cast<PlayerCharacter*>(c->get_widget())) {
        return pc;
      }
    }
  }
  return NULL;
}

std::ostream &operator<<(std::ostream &out, Cell &cell) {
  if (cell.widget) return out << cell.widget->to_char();
  else return out << cell.terrain;
}
