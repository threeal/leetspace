#include <string>

extern "C" {
int countGoodSubstrings(char* s);
}

int solution_c(std::string s) {
  return countGoodSubstrings(s.data());
}
