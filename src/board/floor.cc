#include <cstdlib>
#include <algorithm>

#include "floor.h"
#include "../debug.h"
#include "../factories/hostile_factory.h"
#include "../factories/potion_factory.h"
#include "../factories/gold_factory.h"
#include "../widgets/characters/hostiles/human.h"
#include "../widgets/characters/hostiles/dwarf.h"
#include "../widgets/characters/hostiles/halfling.h"
#include "../widgets/characters/hostiles/elf.h"
#include "../widgets/characters/hostiles/orc.h"
#include "../widgets/characters/hostiles/merchant.h"
#include "../widgets/items/gold/dragon_hoard.h"
#include "../widgets/items/gold/merchant_hoard.h"
#include "../widgets/items/gold/small_gold_pile.h"
#include "../widgets/items/gold/normal_gold_pile.h"
#include "../widgets/items/potions/wounddef.h"
#include "../widgets/items/potions/woundatk.h"
#include "../widgets/items/potions/boostdef.h"
#include "../widgets/items/potions/boostatk.h"
#include "../widgets/items/potions/restorehealth.h"
#include "../widgets/items/potions/poisonhealth.h"

const int FLOOR_ROWS = 25;
const int FLOOR_COLS = 79;

Floor::Floor(TextDisplay *display, PlayerCharacter *pc) : display(display), pc(pc) {}

Floor::~Floor() {
  for (int row = 0; row < FLOOR_ROWS; row++) {
    for (int col = 0; col < FLOOR_COLS; col++) {
      delete grid[row][col];
    }
    delete grid[row];
  }
  delete grid;

  for (std::vector<Chamber*>::iterator c = chambers.begin(); c != chambers.end(); c++) delete *c;
  for (std::vector<Potion*>::iterator p = potions.begin(); p != potions.end(); p++) delete *p;
  for (std::vector<Hostile*>::iterator h = hostiles.begin(); h != hostiles.end(); h++) delete *h;
  for (std::vector<Gold*>::iterator g = gold.begin(); g != gold.end(); g++) delete *g;

  DEBUG("Done freeing floor");
}

void Floor::generate() {
  int pc_chamber    = rand() % chambers.size();
  int stair_chamber = rand() % chambers.size();
  
  if (pc_chamber == stair_chamber) {
    stair_chamber = (stair_chamber + 1) % chambers.size();
  }

  DEBUG("Chambers given");

  chambers[pc_chamber]->spawn(pc);
  chambers[stair_chamber]->make_stair();

  DEBUG("Player character and stair added");

  hostiles.resize(20);
  potions.resize(10);
  gold.resize(10);

  std::generate(potions.begin(), potions.end(), PotionFactory::generator);
  DEBUG("Potions generated");
  for (std::vector<Potion*>::iterator p = potions.begin(); p != potions.end(); p++) random_chamber_spawn(*p);
  DEBUG(potions.size() << " potions added");

  std::generate(gold.begin(), gold.end(), GoldFactory::generator);
  DEBUG("Gold generated");
  for (std::vector<Gold*>::iterator g = gold.begin(); g != gold.end(); g++) random_chamber_spawn(*g);
  DEBUG(gold.size() << " gold piles added");

  std::generate(hostiles.begin(), hostiles.end(), HostileFactory::generator);
  DEBUG("Hostiles generated");
  for (std::vector<Hostile*>::iterator h = hostiles.begin(); h != hostiles.end(); h++) random_chamber_spawn(*h);
  DEBUG(hostiles.size() << " hostiles added");

  DEBUG("Floor generated");
}

void Floor::hostile_turn() {
  for (int row = 0; row < FLOOR_ROWS; row++) {
    for (int col = 0; col < FLOOR_COLS; col++) {
      if (!grid[row][col]) continue;
      if (Hostile *h = dynamic_cast<Hostile*>(grid[row][col]->get_widget())) {
        if (!h->did_move()) h->take_turn();
      }
    }
  }

  for (std::vector<Hostile*>::iterator h = hostiles.begin(); h != hostiles.end(); h++) (*h)->reset();
}

void Floor::random_chamber_spawn(Widget *w) {
  int i = rand() % chambers.size();
  chambers[i]->spawn(w);
}

std::istream &operator>>(std::istream &in, Floor &floor) {
  floor.grid = new Cell**[FLOOR_ROWS];
  for (int row = 0; row < FLOOR_ROWS; row++) {
    floor.grid[row] = new Cell*[FLOOR_COLS];
    for (int col = 0; col < FLOOR_COLS; col++) {
      char c;
      in >> std::noskipws >> c;

      switch (c) {
        case ' ':  floor.grid[row][col] = NULL; continue;
        case '|':  floor.grid[row][col] = new Cell(row, col, floor.display, V_WALL); continue;
        case '-':  floor.grid[row][col] = new Cell(row, col, floor.display, H_WALL); continue;
        case '.':  floor.grid[row][col] = new Cell(row, col, floor.display, TILE); continue;
        case '+':  floor.grid[row][col] = new Cell(row, col, floor.display, DOOR); continue;
        case '#':  floor.grid[row][col] = new Cell(row, col, floor.display, PATHWAY); continue;
        case '\\': floor.grid[row][col] = new Cell(row, col, floor.display, STAIR); continue;
        default: break;
      }

      Cell *cell = floor.grid[row][col] = new Cell(row, col, floor.display, TILE);
      Widget *w;

      switch (c) {
        case '@': w = floor.pc; break;
        case 'E': w = new Elf(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case 'H': w = new Human(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case 'D': w = new Dwarf(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case 'L': w = new Halfling(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case 'O': w = new Orc(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case 'M': w = new Merchant(); floor.hostiles.push_back(static_cast<Hostile*>(w)); break;
        case '0': w = new RestoreHealth(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '1': w = new BoostAtk(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '2': w = new BoostDef(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '3': w = new PoisonHealth(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '4': w = new WoundAtk(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '5': w = new WoundDef(); floor.potions.push_back(static_cast<Potion*>(w)); break;
        case '6': w = new NormalGoldPile(); floor.gold.push_back(static_cast<Gold*>(w)); break;
        case '7': w = new SmallGoldPile(); floor.gold.push_back(static_cast<Gold*>(w)); break;
        case '8': w = new MerchantHoard(); floor.gold.push_back(static_cast<Gold*>(w)); break;
        case '9': w = new DragonHoard(false); floor.gold.push_back(static_cast<Gold*>(w)); break;
        default: break;
      }

      w->set_pos(cell);
    }
    in.get();
  }

  for (int row = 1; row < FLOOR_ROWS - 1; row++) {
    for (int col = 1; col < FLOOR_COLS - 1; col++) {
      if (!floor.grid[row][col]) continue;
      floor.grid[row][col]->add_neighbour(NO, floor.grid[row - 1][col]);
      floor.grid[row][col]->add_neighbour(NE, floor.grid[row - 1][col + 1]);
      floor.grid[row][col]->add_neighbour(EA, floor.grid[row][col + 1]);
      floor.grid[row][col]->add_neighbour(SE, floor.grid[row + 1][col + 1]);
      floor.grid[row][col]->add_neighbour(SO, floor.grid[row + 1][col]);
      floor.grid[row][col]->add_neighbour(SW, floor.grid[row + 1][col - 1]);
      floor.grid[row][col]->add_neighbour(WE, floor.grid[row][col - 1]);
      floor.grid[row][col]->add_neighbour(NW, floor.grid[row - 1][col -1]);
    }
  }

  for (int row = 1; row < FLOOR_ROWS - 1; row++) {
    for (int col = 1; col < FLOOR_COLS - 1; col++) {
      Cell *cell = floor.grid[row][col];

      if (!cell || cell->get_terrain() != TILE || cell->get_chamber()) continue;

      Chamber *c = new Chamber();
      cell->set_chamber(c);
      floor.chambers.push_back(c);
      DEBUG("Added chambers[" << floor.chambers.size() - 1 << "] = " << c);
    }
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, Floor &floor) {
  for (int row = 0; row < FLOOR_ROWS; row++) {
    for (int col = 0; col < FLOOR_COLS; col++) {
      if (floor.grid[row][col]) out << *floor.grid[row][col];
      else out << ' ';
    }
    out << std::endl;
  }

  return out;
}
