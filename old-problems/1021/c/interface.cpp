#include <string>

extern "C" {
char* removeOuterParentheses(char* s);
}

std::string solution_c(std::string s) {
  return removeOuterParentheses(s.data());
}
