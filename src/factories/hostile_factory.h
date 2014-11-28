#ifndef __HOSTILE_FACTORY_H__
#define __HOSTILE_FACTORY_H__

#include <cstdlib>
#include <memory>
#include "factory.h"
#include "../widgets/characters/hostiles/hostile.h"

class HostileFactory {
    static HostileFactory *instance;
    static void delete_instance();

    Factory<Hostile> factory;

    HostileFactory();
  public:
    static Hostile *generator();
};

#endif
