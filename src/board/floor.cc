#include "floor.h"
#include "../debug.h"
#include "../factories/hostile_factory.h"
#include "../factories/potion_factory.h"
#include "../factories/gold_factory.h"
#include <cstdlib>
#include <algorithm>

const int FLOOR_ROWS = 25;
const int FLOOR_COLS = 79;

Floor::Floor(TextDisplay *display) : display(display) {
  hostiles.resize(20);
  potions.resize(10);
  gold.resize(10);
}

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

void Floor::generate(PlayerCharacter *pc) {
  int pc_chamber    = rand() % chambers.size();
  int stair_chamber = rand() % chambers.size();

  DEBUG(pc_chamber << " " << stair_chamber);
  
  if (pc_chamber == stair_chamber) {
    stair_chamber = (stair_chamber + 1) % chambers.size();
  }

  DEBUG("Chambers given");

  chambers[pc_chamber]->spawn(pc);
  chambers[stair_chamber]->make_stair();

  DEBUG("Player character and stair added");

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
        case '|': floor.grid[row][col] = new Cell(row, col, floor.display, V_WALL); break;
        case '-': floor.grid[row][col] = new Cell(row, col, floor.display, H_WALL); break;
        case '.': floor.grid[row][col] = new Cell(row, col, floor.display, TILE); break;
        case '+': floor.grid[row][col] = new Cell(row, col, floor.display, DOOR); break;
        case '#': floor.grid[row][col] = new Cell(row, col, floor.display, PATHWAY); break;
        default:  floor.grid[row][col] = NULL; break;
      }
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
