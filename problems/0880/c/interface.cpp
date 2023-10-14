#include <string>

extern "C" {
char* decodeAtIndex(char* s, int k);
}

std::string solution_c(const std::string& s, const int& k) {
  auto s_copy = s;
  return decodeAtIndex(s_copy.data(), k);
}
