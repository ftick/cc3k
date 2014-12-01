#include "human.h"
#include "../../items/gold/gold.h"

Human::Human() : Hostile(140, 20, 20, NORMAL_GOLD_PILE * 2) {}

char Human::to_char() const {
  return 'H';
}
