#include "merchant.h"

Merchant::Merchant() : Hostile(30, 70, 5) {}

char Merchant::to_char() const {
  return 'M';
}
