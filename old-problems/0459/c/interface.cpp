#include <string>

extern "C" {
bool repeatedSubstringPattern(char* s);
}

bool solution_c(std::string s) {
  return repeatedSubstringPattern(s.data());
}
