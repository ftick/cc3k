#include <iostream>
#include <cstdlib>
#include <sstream>

#include "board/game.h"

using namespace std;

int main(int argc, char **argv) {
  char *floor_plan = NULL;
  if (argc >= 2) {
    floor_plan = argv[1];
    cerr << "Using " << floor_plan << " as floor plan..." << endl;

    if (argc == 3) {
      istringstream ss(argv[2]);
      int seed;
      ss >> seed;
      cerr << "Using " << seed << " as random number generator seed..." << endl;
      srand(seed);
    }
  }

  bool exit = false;

  do {
    Game *g = new Game(floor_plan);

    g->play();
    if (g->is_won() || g->is_lost()) {
      char c;
      cout << "Would you like to play again? (Y/n) ";
      cin >> c;
      exit = c == 'n';
    } else if (g->was_quit()) {
      exit = true;
    }

    delete g;
  } while (!exit);

  return 0;
}
