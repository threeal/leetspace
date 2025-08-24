#include <string>

extern "C" {
int countKConstraintSubstrings(char* s, int k);
}

int solution_c(std::string s, int k) {
  return countKConstraintSubstrings(s.data(), k);
}
