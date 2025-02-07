#include <string>

extern "C" {
bool isNumber(char* s);
}

bool solution_c(std::string s) {
  return isNumber(s.data());
}
