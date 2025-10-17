#include <string>

extern "C" {
bool hasSameDigits(char* s);
}

bool solution_c(std::string s) {
  return hasSameDigits(s.data());
}
