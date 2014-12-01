#include "shade.h"

Shade::Shade() : PlayerCharacter(125, 125, 25, 25) {}

int Shade::score() {
  return 1.5 * PlayerCharacter::score();
}

std::string Shade::race() {
  return "Shade";
}
