#include <string>

extern "C" {
int maxLengthBetweenEqualCharacters(char* s);
}

int solution_c(std::string s) {
  return maxLengthBetweenEqualCharacters(s.data());
}
