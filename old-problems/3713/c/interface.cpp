#include <string>

extern "C" {
int longestBalanced(char* s);
}

int solution_c(std::string s) {
  return longestBalanced(s.data());
}
