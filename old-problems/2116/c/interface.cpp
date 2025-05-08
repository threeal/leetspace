#include <string>

extern "C" {
bool canBeValid(char* s, char* locked);
}

bool solution_c(std::string s, std::string locked) {
  return canBeValid(s.data(), locked.data());
}
