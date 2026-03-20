#include <string>

extern "C" {
bool isSubstringPresent(char* s);
}

bool solution_c(std::string s) {
  return isSubstringPresent(s.data());
}
