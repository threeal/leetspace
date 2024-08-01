#include <string>

extern "C" {
int minimumSwap(char* s1, char* s2);
}

int solution_c(std::string s1, std::string s2) {
  return minimumSwap(s1.data(), s2.data());
}
