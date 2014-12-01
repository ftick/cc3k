#include "halfling.h"
#include <cstdlib>

Halfling::Halfling() : Hostile(100, 15, 20) {}

char Halfling::to_char() const {
  return 'L';
}

int Halfling::defend(Character &other) {
  int coin = rand() % 2;
  if (coin) {
    return -1;
  } else {
    return Hostile::defend(other);
  }
}
