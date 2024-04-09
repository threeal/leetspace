#include <string>

extern "C" {
bool checkValidString(char* s);
}

bool solution_c(std::string s) {
  return checkValidString(s.data());
}
