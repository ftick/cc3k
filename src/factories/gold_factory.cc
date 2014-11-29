#include <cstdlib>

#include "gold_factory.h"
#include "../widgets/items/gold/dragon_hoard.h"
#include "../widgets/items/gold/small_gold_pile.h"
#include "../widgets/items/gold/normal_gold_pile.h"

GoldFactory *GoldFactory::instance = NULL;

GoldFactory::GoldFactory() {
  factory.add(5, creator<Gold, SmallGoldPile>);
  factory.add(2, creator<Gold, NormalGoldPile>);
  factory.add(1, creator<Gold, DragonHoard>);
  std::atexit(GoldFactory::delete_instance);
}

Gold *GoldFactory::generator() {
  if (!instance) instance = new GoldFactory;
  return instance->factory();
}

void GoldFactory::delete_instance() {
  delete instance;
}
