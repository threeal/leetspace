#include <string>

extern "C" {
char* largestOddNumber(char* num);
}

std::string solution_c(std::string num) {
  return largestOddNumber(num.data());
}
