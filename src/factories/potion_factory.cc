#include <cstdlib>

#include "potion_factory.h"
#include "../widgets/items/potions/wounddef.h"
#include "../widgets/items/potions/woundatk.h"
#include "../widgets/items/potions/boostdef.h"
#include "../widgets/items/potions/boostatk.h"
#include "../widgets/items/potions/restorehealth.h"
#include "../widgets/items/potions/poisonhealth.h"

PotionFactory *PotionFactory::instance = NULL;

PotionFactory::PotionFactory() {
  factory.add(1, creator<Potion, WoundDef>);
  factory.add(1, creator<Potion, WoundAtk>);
  factory.add(1, creator<Potion, BoostDef>);
  factory.add(1, creator<Potion, BoostAtk>);
  factory.add(1, creator<Potion, RestoreHealth>);
  factory.add(1, creator<Potion, PoisonHealth>);
  std::atexit(PotionFactory::delete_instance);
}

Potion *PotionFactory::generator() {
  if (!instance) instance = new PotionFactory;
  return instance->factory();
}

void PotionFactory::delete_instance() {
  delete instance;
}
