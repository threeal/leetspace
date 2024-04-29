#include <string>

extern "C" {
int longestIdealString(char* s, int k);
}

int solution_c(std::string s, int k) {
  return longestIdealString(s.data(), k);
}
