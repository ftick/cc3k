#include "hostile.h"
#include <climits>

Hostile::Hostile(int health, int atk, int def) :
  Character(health, INT_MAX, atk, def) {}

void Hostile::take_turn() {}

char Hostile::to_char() const {
  return '?';
}
