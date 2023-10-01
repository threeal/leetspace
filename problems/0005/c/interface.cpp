#include <string>

extern "C" {
char* longestPalindrome(char* s);
}

std::string solution_c(std::string s) {
  return longestPalindrome(const_cast<char*>(s.c_str()));
}
