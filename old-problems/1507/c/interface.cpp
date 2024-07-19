#include <string>

extern "C" {
char* reformatDate(char* date);
}

std::string solution_c(std::string date) {
  return reformatDate(date.data());
}
