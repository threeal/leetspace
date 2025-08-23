#include <string>

extern "C" {
char* robotWithString(char* s);
}

std::string solution_c(std::string s) {
  return robotWithString(s.data());
}
