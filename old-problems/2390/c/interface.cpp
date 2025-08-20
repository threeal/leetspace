#include <string>

extern "C" {
char* removeStars(char* s);
}

std::string solution_c(std::string s) {
  return removeStars(s.data());
}
