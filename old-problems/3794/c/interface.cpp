#include <string>

extern "C" {
char* reversePrefix(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return reversePrefix(s.data(), k);
}
