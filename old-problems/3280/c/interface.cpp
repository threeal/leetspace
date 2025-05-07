#include <string>

extern "C" {
char* convertDateToBinary(char* date);
}

std::string solution_c(std::string date) {
  return convertDateToBinary(date.data());
}
