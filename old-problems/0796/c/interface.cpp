#include <string>

extern "C" {
bool rotateString(char* s, char* goal);
}

bool solution_c(std::string s, std::string goal) {
  return rotateString(s.data(), goal.data());
}
