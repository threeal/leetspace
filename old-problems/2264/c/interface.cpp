#include <string>

extern "C" {
char* largestGoodInteger(char* num);
}

std::string solution_c(std::string num) {
  return largestGoodInteger(num.data());
}
