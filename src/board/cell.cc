#include "cell.h"

Cell::Cell(int row, int col, TextDisplay *display, terrain_t terrain) : row(row), col(col), display(display), terrain(terrain) {}

void Cell::add_neighbour(direction_t dir, Cell* neighbour) {
  neighbours[dir] = neighbour;
}

void Cell::get_neighbour(direction_t dir) {
  neighbours[dir];
}

std::ostream &operator<<(std::ostream &out, Cell &cell) {
  if (cell.widget) return out << cell.widget;
  else return out << cell.terrain;
}

std::ostream &operator<<(std::ostream &out, terrain_t terrain) {
  switch (terrain) {
    case V_WALL:  return out << '|';
    case H_WALL:  return out << '-';
    case TILE:    return out << '.';
    case DOOR:    return out << '+';
    case PATHWAY: return out << '#';
    default:      return out << ' ';
  }
}
