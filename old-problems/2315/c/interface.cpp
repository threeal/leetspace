#include <string>

extern "C" {
int countAsterisks(char* s);
}

int solution_c(std::string s) {
  return countAsterisks(s.data());
}
