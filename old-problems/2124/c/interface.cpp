#include <string>

extern "C" {
bool checkString(char* s);
}

bool solution_c(std::string s) {
  return checkString(s.data());
}
