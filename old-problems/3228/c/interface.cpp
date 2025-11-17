#include <string>

extern "C" {
int maxOperations(char* s);
}

int solution_c(std::string s) {
  return maxOperations(s.data());
}
