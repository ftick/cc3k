#include "cell.h"
#include "../debug.h"
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

  DEBUG("Setting cell (" << row << ", " << col << ") to " << c);

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

Cell *Cell::get_unoccupied_tile_neighbour() {
  int dir  = rand() % 8;
  int orig = dir;

  while (neighbours[static_cast<direction_t>(dir)]->get_terrain() != TILE ||
         neighbours[static_cast<direction_t>(dir)]->get_widget()) {
    dir++;
    if (dir == orig) {
      DEBUG("Unoccupied tile neighbour not found!");
      return NULL;
    }
  }

  return neighbours[static_cast<direction_t>(dir)];
}

void Cell::set_widget(Widget *w) {
  widget = w;
}

Widget *Cell::get_widget() {
  return widget;
}

std::ostream &operator<<(std::ostream &out, Cell &cell) {
  if (cell.widget) return out << cell.widget->to_char();
  else return out << cell.terrain;
}

std::ostream &operator<<(std::ostream &out, terrain_t terrain) {
  switch (terrain) {
    case V_WALL:  return out << '|';
    case H_WALL:  return out << '-';
    case TILE:    return out << '.';
    case DOOR:    return out << '+';
    case PATHWAY: return out << '#';
    case STAIR:   return out << '\\';
    default:      return out << ' ';
  }
}
