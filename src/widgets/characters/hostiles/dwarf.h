#ifndef __DWARF_H__
#define __DWARF_H__

#include "hostile.h"

class Dwarf : public Hostile {
  public:
    Dwarf();
    char to_char() const;
};

#endif
