#include <string>

extern "C" {
int findTheLongestSubstring(char* s);
}

int solution_c(std::string s) {
  return findTheLongestSubstring(s.data());
}
