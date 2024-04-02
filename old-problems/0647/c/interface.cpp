#include <string>

extern "C" {
int countSubstrings(char* s);
}

int solution_c(std::string s) {
  return countSubstrings(s.data());
}
