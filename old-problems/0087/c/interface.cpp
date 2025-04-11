#include <string>

extern "C" {
bool isScramble(char* s1, char* s2);
}

bool solution_c(std::string s1, std::string s2) {
  return isScramble(s1.data(), s2.data());
}
