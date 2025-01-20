#include <string>

extern "C" {
int lengthOfLongestSubstring(char* s);
}

int solution_c(std::string s) {
  return lengthOfLongestSubstring(s.data());
}
