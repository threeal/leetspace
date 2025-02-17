#include <string>

extern "C" {
char* clearDigits(char* s);
}

std::string solution_c(std::string s) {
  return clearDigits(s.data());
}
