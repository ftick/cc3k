#include "orc.h"

Orc::Orc() : Hostile(180, 30, 20) {}

char Orc::to_char() const {
  return 'O';
}
