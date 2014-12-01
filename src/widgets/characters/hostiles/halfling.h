#ifndef __HALFLING_H__
#define __HALFLING_H__

#include "hostile.h"

class Halfling : public Hostile {
  public:
    Halfling();
    char to_char() const;
    int defend(Character &other);
};

#endif
