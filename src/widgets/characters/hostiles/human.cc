#include "human.h"

Human::Human() : Hostile(140, 20, 20) {}

char Human::to_char() const {
  return 'H';
}
