#include "widget.h"

Widget::Widget() {}

void Widget::set_pos(Cell *new_pos) {
  new_pos->set_widget(this);
  pos = new_pos;
}

Cell *Widget::get_pos() const {
  return pos;
}

Widget::~Widget() {}
