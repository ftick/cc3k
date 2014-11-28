#include "chamber.h"
#include <cstdlib>

Chamber::Chamber() {}

void Chamber::add_cell(Cell *c) {
  cells.push_back(c);
}

void Chamber::spawn(Widget *w) {
  int i = rand() % cells.size();

  while (cells[i]->get_widget()) {
    i = (i + 1) % cells.size();
  }

  cells[i]->set_widget(w);
  w->set_pos(cells[i]);
}

void Chamber::make_stair() {
  int i = rand() % cells.size();
  cells[i]->set_terrain(STAIR);
  cells.erase(cells.begin() + i);
}
