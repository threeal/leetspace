#include <string>

extern "C" {
char* reverseWords(char* s);
}

std::string solution_c(const std::string& s) {
  auto s_copy = s;
  return reverseWords(s_copy.data());
}
