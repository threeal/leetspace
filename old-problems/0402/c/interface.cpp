#include <string>

extern "C" {
char* removeKdigits(char* num, int k);
}

std::string solution_c(std::string num, int k) {
  return removeKdigits(num.data(), k);
}
