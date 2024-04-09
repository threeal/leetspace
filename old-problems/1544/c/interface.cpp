#include <string>

extern "C" {
char* makeGood(char* s);
}

std::string solution_c(std::string s) {
  return makeGood(s.data());
}
