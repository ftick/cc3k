#include <cstdlib>

#include "hostile_factory.h"
#include "../widgets/characters/hostiles/human.h"
#include "../widgets/characters/hostiles/dwarf.h"
#include "../widgets/characters/hostiles/halfling.h"
#include "../widgets/characters/hostiles/elf.h"
#include "../widgets/characters/hostiles/orc.h"
#include "../widgets/characters/hostiles/merchant.h"

HostileFactory *HostileFactory::instance = NULL;

HostileFactory::HostileFactory() {
  factory.add(4, creator<Hostile, Human>);
  factory.add(3, creator<Hostile, Dwarf>);
  factory.add(5, creator<Hostile, Halfling>);
  factory.add(2, creator<Hostile, Elf>);
  factory.add(2, creator<Hostile, Orc>);
  factory.add(1, creator<Hostile, Merchant>);
  std::atexit(HostileFactory::delete_instance);
}

Hostile *HostileFactory::generator() {
  if (!instance) instance = new HostileFactory;
  return instance->factory();
}

void HostileFactory::delete_instance() {
  delete instance;
}
