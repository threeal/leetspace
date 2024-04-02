#include <string>

extern "C" {
int countPalindromicSubsequence(char* s);
}

int solution_c(std::string s) {
  return countPalindromicSubsequence(s.data());
}
