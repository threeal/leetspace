#include <string>

extern "C" {
char* reverseByType(char* s);
}

std::string solution_c(std::string s) {
  return reverseByType(s.data());
}
