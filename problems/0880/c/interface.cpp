#include <string>

extern "C" {
char* decodeAtIndex(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return decodeAtIndex(s.data(), k);
}
