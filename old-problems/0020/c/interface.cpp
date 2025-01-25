#include <string>

extern "C" {
bool isValid(char* s);
}

bool solution_c(std::string s) {
  return isValid(s.data());
}
