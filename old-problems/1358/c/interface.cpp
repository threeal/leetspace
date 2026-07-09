#include <string>

extern "C" {
int numberOfSubstrings(char* s);
}

int solution_c(std::string s) {
  return numberOfSubstrings(s.data());
}
