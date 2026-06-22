#include <string>

extern "C" {
char* processStr(char* s);
}

std::string solution_c(std::string s) {
  return processStr(s.data());
}
