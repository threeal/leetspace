#include <string>

extern "C" {
int minOperations(char* s);
}

int solution_c(std::string s) {
  return minOperations(s.data());
}
