#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "hostile.h"

class Human : public Hostile {
  public:
    Human();
    char to_char() const;
};

#endif
