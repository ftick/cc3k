#include "troll.h"

Troll::Troll() : PlayerCharacter(120, 120, 25, 15) {}

void Troll::take_turn() {
  PlayerCharacter::take_turn();
  set_health(get_health() + 5);
}

std::string Troll::race() {
  return "Troll";
}
