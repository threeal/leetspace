#include <string>

extern "C" {
char* intToRoman(int num);
}

std::string solution_c(int num) {
  return intToRoman(num);
}
