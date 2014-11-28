#include "halfling.h"

Halfling::Halfling() : Hostile(100, 15, 20) {}

char Halfling::to_char() const {
  return 'L';
}
