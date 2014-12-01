#ifndef __ELF_H__
#define __ELF_H__

#include "hostile.h"
#include "../player_characters/drow.h"

class Elf : public Hostile {
  public:
    Elf();
    char to_char() const;
    int attack(Character &other);
    int attack(Drow &other);
};

#endif
