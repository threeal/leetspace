#include <string>

extern "C" {
bool judgeCircle(char* moves);
}

bool solution_c(std::string moves) {
  return judgeCircle(moves.data());
}
