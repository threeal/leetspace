#include <string>

extern "C" {
int longestValidParentheses(char* s);
}

int solution_c(std::string s) {
  return longestValidParentheses(s.data());
}
