#include <string>

extern "C" {
bool halvesAreAlike(char* s);
}

int solution_c(std::string s) {
  return halvesAreAlike(s.data());
}
