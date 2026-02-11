#include <string>

extern "C" {
char* reverseOnlyLetters(char* s);
}

std::string solution_c(std::string s) {
  return reverseOnlyLetters(s.data());
}
