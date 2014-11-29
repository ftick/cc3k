#include "dragon_hoard.h"
#include "../../../debug.h"

DragonHoard::DragonHoard(bool spawn) : Gold(DRAGON_HOARD) {
  DEBUG("Dragonnnnn TIMEEEEEEE");
  if (spawn) {
    dragon = new Dragon(this);
  } else {
    // TODO
  }
}

DragonHoard::~DragonHoard() {
  delete dragon;
}

PlayerCharacter *DragonHoard::use(PlayerCharacter *pc) {
  if (dragon->is_alive()) return pc;
  return Gold::use(pc);
}

void DragonHoard::set_pos(Cell *cell) {
  Widget::set_pos(cell);
  dragon->set_pos(cell->get_unoccupied_tile_neighbour());
}
