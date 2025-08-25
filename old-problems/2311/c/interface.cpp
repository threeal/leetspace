#include <string>

extern "C" {
int longestSubsequence(char* s, int k);
}

int solution_c(std::string s, int k) {
  return longestSubsequence(s.data(), k);
}
