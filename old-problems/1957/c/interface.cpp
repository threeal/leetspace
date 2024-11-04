#include <string>

extern "C" {
char* makeFancyString(char* s);
}

std::string solution_c(std::string s) {
  return makeFancyString(s.data());
}
