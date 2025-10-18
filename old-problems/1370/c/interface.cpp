#include <string>

extern "C" {
char* sortString(char* s);
}

std::string solution_c(std::string s) {
  return sortString(s.data());
}
