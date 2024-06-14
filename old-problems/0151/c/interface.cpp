#include <string>

extern "C" {
char* reverseWords(char* s);
}

std::string solution_c(std::string s) {
  return reverseWords(s.data());
}
