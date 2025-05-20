#include <string>

extern "C" {
char* stringHash(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return stringHash(s.data(), k);
}
