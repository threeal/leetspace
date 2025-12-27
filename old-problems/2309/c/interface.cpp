#include <string>

extern "C" {
char* greatestLetter(char* s);
}

std::string solution_c(std::string s) {
  return greatestLetter(s.data());
}
