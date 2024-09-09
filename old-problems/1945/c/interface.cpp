#include <string>

extern "C" {
int getLucky(char* s, int k);
}

int solution_c(std::string s, int k) {
  return getLucky(s.data(), k);
}
