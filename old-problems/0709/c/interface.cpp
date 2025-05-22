#include <string>

extern "C" {
char* toLowerCase(char* s);
}

std::string solution_c(std::string s) {
  return toLowerCase(s.data());
}
