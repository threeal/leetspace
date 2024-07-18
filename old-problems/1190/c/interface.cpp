#include <string>

extern "C" {
char* reverseParentheses(char* s);
}

std::string solution_c(std::string s) {
  return reverseParentheses(s.data());
}
