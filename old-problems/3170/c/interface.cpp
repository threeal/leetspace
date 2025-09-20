#include <string>

extern "C" {
char* clearStars(char* s);
}

std::string solution_c(std::string s) {
  return clearStars(s.data());
}
