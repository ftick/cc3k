#include "floor.h"

const int FLOOR_ROWS = 79;
const int FLOOR_COLS = 25;

Floor::Floor(TextDisplay *display) : display(display) {}

Floor::Floor(const Floor &floor) : display(floor.display) {}

Floor::~Floor() {
  for (int row = 0; row < FLOOR_ROWS; row++) {
    for (int col = 0; col < FLOOR_COLS; col++) {
      delete grid[row][col];
    }
  }
}

void Floor::generate() {}

std::istream &operator>>(std::istream &in, Floor &floor) {
  floor.grid = new Cell**[FLOOR_ROWS];
  for (int row = 0; row < FLOOR_ROWS; row++) {
    floor.grid[row] = new Cell*[FLOOR_COLS];
    for (int col = 0; col < FLOOR_COLS; col++) {
      char c;
      in >> c;
      switch (c) {
        case '|': floor.grid[row][col] = new Cell(row, col, floor.display, V_WALL); break;
        case '-': floor.grid[row][col] = new Cell(row, col, floor.display, H_WALL); break;
        case '.': floor.grid[row][col] = new Cell(row, col, floor.display, TILE); break;
        case '+': floor.grid[row][col] = new Cell(row, col, floor.display, DOOR); break;
        case '#': floor.grid[row][col] = new Cell(row, col, floor.display, PATHWAY); break;
        default:  floor.grid[row][col] = NULL; break;
      }
    }
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

  return in;
}
