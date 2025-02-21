#include <string>

extern "C" {
int numTilePossibilities(char* tiles);
}

int solution_c(std::string tiles) {
  return numTilePossibilities(tiles.data());
}
