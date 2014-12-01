#include "vampire.h"
#include <climits>

Vampire::Vampire() : PlayerCharacter(50, INT_MAX, 25, 25) {}

int Vampire::attack(Character &other) {
  int dmg = PlayerCharacter::attack(other);
  if (dmg != -1) set_health(get_health() - 5);
  return dmg;
}

int Vampire::attack(Dwarf &other) {
  int dmg = PlayerCharacter::attack(other);
  if (dmg != -1) set_health(get_health() + 5);
  return dmg;
}

std::string Vampire::race() {
  return "Vampire";
}
