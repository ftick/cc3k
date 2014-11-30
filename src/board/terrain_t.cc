#include "terrain_t.h"

std::ostream &operator<<(std::ostream &out, terrain_t terrain) {
  switch (terrain) {
    case V_WALL:  return out << '|';
    case H_WALL:  return out << '-';
    case TILE:    return out << '.';
    case DOOR:    return out << '+';
    case PATHWAY: return out << '#';
    case STAIR:   return out << '\\';
    default:      return out << ' ';
  }
}
