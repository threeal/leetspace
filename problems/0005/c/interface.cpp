#include <internal.hpp>
#include <string>

extern "C" {
char* longestPalindrome(char* s);
}

template <>
std::string solution_c(const std::string& s) {
  auto s_copy = s;
  return longestPalindrome(s_copy.data());
}
