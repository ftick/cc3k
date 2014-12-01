#include "game.h"
#include "../debug.h"
#include "../widgets/characters/player_characters/shade.h"
#include "../widgets/characters/player_characters/drow.h"
#include "../widgets/characters/player_characters/vampire.h"
#include "../widgets/characters/player_characters/goblin.h"
#include "../widgets/characters/player_characters/troll.h"
#include "../buffs/buff.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

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
  switch (character_code) {
    case 's': return new Shade();
    case 'd': return new Drow();
    case 'v': return new Vampire();
    case 'g': return new Goblin();
    case 't': return new Troll();
  }
  std::cerr << "Invalid choice..." << std::endl;
  std::exit(1);
  return NULL;
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
    play_floor(level);
    if (!pc->has_reached_stair()) break;
  }

  if (!quit) {
    if (!pc->has_reached_stair()) {
      std::cout << "Game lost!" << std::endl;
    } else {
      std::cout << "Game won!" << std::endl;
    }
    std::cout << "Score: " << pc->score() << std::endl;
  }
}

void Game::play_floor(int level) {
  PlayerCharacter *p = pc;
  std::string action = level == 1 ? "Player character has spawned" : "Player character has reached the next level";
  std::string race = pc->race();

  do {
    char command;
    bool success = true;

    std::cout << *floor;
    std::cout << "Race: " << race << " Gold: " << std::setw(56 - race.length()) << std::left << p->get_gold() << "Floor " << level << std::endl;
    std::cout << "HP: " << p->get_health() << std::endl;
    std::cout << "Atk: " << p->get_atk() << std::endl;
    std::cout << "Def: " << p->get_def() << std::endl;
    std::cout << "Action: " << action << std::endl;
    std::cin >> command;

    pc->take_turn();

    switch (command) {
      case 'q': quit = true; return;
      case 'r': return;
      case 'u': {
        direction_t dir = read_direction();
        if (Potion *c = dynamic_cast<Potion *>(p->get_pos()->get_neighbour(dir)->get_widget())) {
          action = "PC uses a potion";
          p = c->use(p);
        } else {
          success = false;
          DEBUG("Not a potion...");
        }
        break;
      }
      case 'a': {
        direction_t dir = read_direction();
        Widget *w = p->get_pos()->get_neighbour(dir)->get_widget();
        if (w) {
          if (Hostile *h = dynamic_cast<Hostile*>(w)) {
            int damage = p->attack(*h);
            std::stringstream ss;
            if (damage == -1) {
              ss << "PC missed!";
            } else {
              ss << "PC dealt " << damage << " to " << h->to_char();
            }
            ss << " (" << h->get_health() << " HP)";
            action = ss.str();
          } else success = false;
        } else success = false;
        break;
      }
      default: {
        action = "PC moves";
        char code[2] = { command };
        std::cin >> code[1];
        direction_t dir = decode_direction(code);
        success = p->move(dir);
      }
    }

    if (!success) {
      action = "Can't do that!";
    } else {
      floor->hostile_turn();
    }
  } while (!is_lost() && !p->has_reached_stair());

  if (dynamic_cast<Buff*>(p)) {
    delete p;
  }
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
