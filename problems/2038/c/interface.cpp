#include <string>

extern "C" {
bool winnerOfGame(char* colors);
}

bool solution_c(const std::string& colors) {
  return winnerOfGame(const_cast<char*>(colors.c_str()));
}
