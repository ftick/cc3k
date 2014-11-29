#include "game.h"
#include "../debug.h"

#include <fstream>

char default_init_file[] = "./config/default.map";

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

Game::Game(const char *init_file) :
    pc(select_player_character()),
    td(new TextDisplay()),
    floor(NULL),
    quit(false),
    random_generation(!init_file),
    in(new std::ifstream(init_file ? init_file : default_init_file)) {}

Game::~Game() {
  delete pc;
  delete floor;
}

void Game::play() {
  for (int level = 1; level <= 5; ++level) {

    DEBUG("Level: " << level);

    delete floor;
    floor = new Floor(td, pc);
    *in >> *floor;
    if (random_generation) floor->generate();
    play_floor();
    if (!pc->has_reached_stair()) return;
  }

  std::cout << "Game won!" << std::endl;
}

void Game::play_floor() {
  PlayerCharacter *p = pc;

  do {
    char command;
    bool success = true;

    std::cout << *floor;
    std::cin >> command;

    pc->take_turn();

    switch (command) {
      case 'q': quit = true; return;
      case 'r': return;
      case 'u': {
        direction_t dir = read_direction();
        if (Potion *c = dynamic_cast<Potion *>(p->get_pos()->get_neighbour(dir)->get_widget())) {
          DEBUG("Using potion");
          p = c->use(p);
        } else {
          DEBUG("Not a potion...");
        }
        break;
      }
      case 'a': {
        direction_t dir = read_direction();
        DEBUG("Attacking");
        //Hostile *h = p->get_cell()->get_neighbour(dir)->get_widget();
        //p->attack(*h);
        break;
      }
      default: {
        DEBUG("Moving");
        char code[2] = { command };
        std::cin >> code[1];
        direction_t dir = decode_direction(code);
        success = p->move(dir);
      }
    }

    DEBUG("Gold: " << pc->get_gold());

    if (!success) {
      DEBUG("Can't do that!");
    }

    if (p->has_reached_stair()) return;
  } while (!is_lost());
}

bool Game::is_won() {
  return pc->has_reached_stair();
}

bool Game::is_lost() {
  return !pc->is_alive();
}

bool Game::was_quit() {
  return quit;
}
