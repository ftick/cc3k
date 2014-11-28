#ifndef __ORC_H__
#define __ORC_H__

#include "hostile.h"

class Orc : public Hostile {
  public:
    Orc();
    char to_char() const;
};

#endif
