#ifndef __TERRAIN_T_H__
#define __TERRAIN_T_H__

#include <iostream>

enum terrain_t {
  V_WALL,
  H_WALL,
  TILE,
  DOOR,
  PATHWAY,
  STAIR
};

std::ostream &operator<<(std::ostream &out, terrain_t terrain);

#endif
