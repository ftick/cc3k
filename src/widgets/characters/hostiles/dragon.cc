#include "dragon.h"

Dragon::Dragon(DragonHoard *hoard) : Hostile(150, 20, 20), hoard(hoard) {}

char Dragon::to_char() const {
  return 'D';
}

bool Dragon::move(direction_t dir) {
  return true;
}