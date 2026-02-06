#include <string>

extern "C" {
char* largestEven(char* s);
}

std::string solution_c(std::string s) {
  return largestEven(s.data());
}
