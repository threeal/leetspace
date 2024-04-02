#include <string>

extern "C" {
bool winnerOfGame(char* colors);
}

bool solution_c(std::string colors) {
  return winnerOfGame(colors.data());
}
