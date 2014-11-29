#ifndef __POTION_FACTORY_H__
#define __POTION_FACTORY_H__

#include <cstdlib>
#include <memory>
#include "factory.h"
#include "../widgets/items/potions/potion.h"

class PotionFactory {
    static PotionFactory *instance;
    static void delete_instance();

    Factory<Potion> factory;

    PotionFactory();
  public:
    static Potion *generator();
};

#endif
