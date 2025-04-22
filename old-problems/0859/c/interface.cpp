#include <string>

extern "C" {
bool buddyStrings(char* s, char* goal);
}

bool solution_c(std::string s, std::string goal) {
  return buddyStrings(s.data(), goal.data());
}
