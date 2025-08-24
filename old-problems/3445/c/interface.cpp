#include <string>

extern "C" {
int maxDifference(char* s, int k);
}

int solution_c(std::string s, int k) {
  return maxDifference(s.data(), k);
}
