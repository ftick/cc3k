#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "../board/cell.h"

class Cell;

class Widget {
    Cell *pos;
  public:
    Widget();
    virtual void set_pos(Cell *pos);
    virtual Cell *get_pos() const;
    virtual char to_char() const = 0;
    virtual ~Widget() = 0;
};

#endif
