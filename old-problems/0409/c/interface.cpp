#include <string>

extern "C" {
int longestPalindrome(char* s);
}

int solution_c(std::string s) {
  return longestPalindrome(s.data());
}
