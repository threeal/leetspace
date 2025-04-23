#include <string>

extern "C" {
int countBinarySubstrings(char* s);
}

int solution_c(std::string s) {
  return countBinarySubstrings(s.data());
}
