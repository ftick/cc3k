#include "widget.h"

Widget::Widget() {}

void Widget::set_pos(Cell *new_pos) {
  pos = new_pos;
}

Cell *Widget::get_pos() const {
  return pos;
}

Widget::~Widget() {}
