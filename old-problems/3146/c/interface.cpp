#include <string>

extern "C" {
int findPermutationDifference(char* s, char* t);
}

int solution_c(std::string s, std::string t) {
  return findPermutationDifference(s.data(), t.data());
}
