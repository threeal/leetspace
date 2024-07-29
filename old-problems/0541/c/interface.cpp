#include <string>

extern "C" {
char* reverseStr(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return reverseStr(s.data(), k);
}
