#include "dwarf.h"

Dwarf::Dwarf() : Hostile(100, 20, 30) {}

char Dwarf::to_char() const {
  return 'D';
}
