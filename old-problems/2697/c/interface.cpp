#include <string>

extern "C" {
char* makeSmallestPalindrome(char* s);
}

std::string solution_c(std::string s) {
  return makeSmallestPalindrome(s.data());
}
