#include "elf.h"

Elf::Elf() : Hostile(140, 30, 10) {}

char Elf::to_char() const {
  return 'E';
}
