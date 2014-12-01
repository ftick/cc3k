#include "goblin.h"

Goblin::Goblin() : PlayerCharacter(110, 110, 15, 20) {}

void Goblin::did_kill(Character &other) {
  PlayerCharacter::did_kill(other);
  set_gold(get_gold() + 5);
}

std::string Goblin::race() {
  return "Goblin";
}
