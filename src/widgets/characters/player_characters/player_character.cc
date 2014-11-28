#include "player_character.h"
#include "../../items/gold.h"

PlayerCharacter::PlayerCharacter(int health, int max_health, int atk, int def) :
  Character(health, max_health, atk, def),
  at_stair(false) {}

void PlayerCharacter::take_turn() {
  Character::take_turn();
  at_stair = false;
}

bool PlayerCharacter::is_pathable(terrain_t t) const {
  return t == TILE || t == PATHWAY || t == DOOR || t == STAIR;
}

char PlayerCharacter::to_char() const {
  return '@';
}

bool PlayerCharacter::has_reached_stair() const {
  return get_pos()->get_terrain() == STAIR;
}

bool PlayerCharacter::move(direction_t dir) {
  Cell *neighbour = get_pos()->get_neighbour(dir);

  if (neighbour && neighbour->get_widget()) {
    if (Gold *gold = dynamic_cast<Gold*>(neighbour->get_widget())) {
      gold->use(this);
      neighbour->set_widget(NULL);
    }
  }

  return Character::move(dir);
}
