#include <string>

extern "C" {
char* longestPalindrome(char* s);
}

std::string solution_c(std::string s) {
  return longestPalindrome(s.data());
}
