#include "chamber.h"
#include "../debug.h"
#include <cstdlib>

Chamber::Chamber() {}

void Chamber::add_cell(Cell *c) {
  cells.push_back(c);
}

void Chamber::spawn(Widget *w) {
  int i    = rand() % cells.size();
  int orig = i;

  //DEBUG("spawning at " << i << " of " << cells.size());

  while (cells[i]->get_widget()) {
    i = (i + 1) % cells.size();
    if (i == orig) {
      DEBUG("Klober!");
      break;
    }
  }

  w->set_pos(cells[i]);
}

void Chamber::make_stair() {
  int i = rand() % cells.size();
  cells[i]->set_terrain(STAIR);
  cells.erase(cells.begin() + i);
}
