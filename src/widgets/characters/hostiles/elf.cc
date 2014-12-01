#include "elf.h"

Elf::Elf() : Hostile(140, 30, 10) {}

char Elf::to_char() const {
  return 'E';
}

int Elf::attack(Character &other) {
  return Hostile::attack(other) + Hostile::attack(other);
}

int Elf::attack(Drow &other) {
  return Hostile::attack(other);
}
