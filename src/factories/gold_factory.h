#ifndef __GOLD_FACTORY_H__
#define __GOLD_FACTORY_H__

#include <cstdlib>
#include <memory>
#include "factory.h"
#include "../widgets/items/gold/gold.h"

class GoldFactory {
    static GoldFactory *instance;
    static void delete_instance();

    Factory<Gold> factory;

    GoldFactory();
  public:
    static Gold *generator();
};

#endif
