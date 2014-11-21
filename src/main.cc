#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc >= 2) {
    cerr << "Using " << argv[1] << " as floor plan..." << endl;
  }
  return 0;
}
