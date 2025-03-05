#include <string>

extern "C" {
int maxDistance(char* s, int k);
}

int solution_c(std::string s, int k) {
  return maxDistance(s.data(), k);
}
