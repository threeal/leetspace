#include <string>

extern "C" {
int minOperations(char* s, int k);
}

int solution_c(std::string s, int k) {
  return minOperations(s.data(), k);
}
