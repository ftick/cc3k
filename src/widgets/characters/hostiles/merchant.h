#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "hostile.h"

class Merchant : public Hostile {
  public:
    Merchant();
    char to_char() const;
};

#endif
