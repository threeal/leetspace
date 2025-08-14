#include <string>

extern "C" {
char* removeTrailingZeros(char* num);
}

std::string solution_c(std::string num) {
  return removeTrailingZeros(num.data());
}
