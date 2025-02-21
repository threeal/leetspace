#include <string>

extern "C" {
char* smallestNumber(char* pattern);
}

std::string solution_c(std::string pattern) {
  return smallestNumber(pattern.data());
}
