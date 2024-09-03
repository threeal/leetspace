#include <string>

extern "C" {
char repeatedCharacter(char* s);
}

char solution_c(std::string s) {
  return repeatedCharacter(s.data());
}
