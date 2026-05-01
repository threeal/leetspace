#include <string>

extern "C" {
int furthestDistanceFromOrigin(char* moves);
}

int solution_c(std::string moves) {
  return furthestDistanceFromOrigin(moves.data());
}
