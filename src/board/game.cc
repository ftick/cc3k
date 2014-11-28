#include "game.h"
#include "../debug.h"

#include <fstream>

char default_init_file[] = "./config/default.map";

PlayerCharacter *select_player_character() {
  char character_code;
  std::cin >> character_code;
  // switch (character_code) {
  //   case 's': return new Shade();
  //   case 'd': return new Drow();
  //   case 'v': return new Vampire();
  //   case 'g': return new Goblin();
  //   case 't': return new Troll();
  // }
  return new PlayerCharacter(120, 120, 25, 25);
}

Game::Game(const char *init_file) : level(1) {
  std::ifstream init(init_file ? init_file : default_init_file);
  td = new TextDisplay();
  pc = select_player_character();
  floor = new Floor(td);
  init >> *floor;
  
  if (!init_file) floor->generate(pc);
}

direction_t decode_direction(char dir[2]) {
  switch (dir[0] + dir[1]) {
    case 'n' + 'o': return NO;
    case 'n' + 'e': return NE;
    case 'e' + 'a': return EA;
    case 's' + 'e': return SE;
    case 's' + 'o': return SO;
    case 's' + 'w': return SW;
    case 'w' + 'e': return WE;
    case 'n' + 'w': return NW;
    default: return NO;
  }
}

direction_t read_direction() {
  char code[2];
  std::cin >> code[0] >> code[1];
  return decode_direction(code);
}

void Game::play() {
  PlayerCharacter *p = pc;

  do {
    char c;
    bool success;

    std::cout << *floor;
    std::cin >> c;

    pc->take_turn();

    switch (c) {
      case 'q': quit = true; return;
      case 'r': return;
      case 'u': {
        direction_t dir = read_direction();
        //Potion *c = p->get_cell()->get_neighbour(dir)->get_widget();
        //p = c->use(p);
        break;
      }
      case 'a': {
        direction_t dir = read_direction();
        //Hostile *h = p->get_cell()->get_neighbour(dir)->get_widget();
        //p->attack(*h);
        break;
      }
      default: {
        char code[2] = { c };
        std::cin >> code[1];
        direction_t dir = decode_direction(code);
        success = p->move(dir);
      }
    }

    if (!success) {
      DEBUG("Can't do that!");
    }

    if (p->has_reached_stair()) {
      DEBUG("Stair reached!");
      if (++level == 6) break;
    }

  } while (!is_lost());

  std::cout << "Game over" << std::endl;
}

bool Game::is_won() {
  return level == 6;
}

bool Game::is_lost() {
  return !pc->is_alive();
}

bool Game::was_quit() {
  return quit;
}
