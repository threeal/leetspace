#include <string>

extern "C" {
char* finalString(char* s);
}

std::string solution_c(std::string s) {
  return finalString(s.data());
}
