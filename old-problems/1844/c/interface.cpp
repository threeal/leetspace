#include <string>

extern "C" {
char* replaceDigits(char* s);
}

std::string solution_c(std::string s) {
  return replaceDigits(s.data());
}
