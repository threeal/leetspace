#include <string>

extern "C" {
int minDeletion(char* s, int k);
}

int solution_c(std::string s, int k) {
  return minDeletion(s.data(), k);
}
