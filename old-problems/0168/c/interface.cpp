#include <string>

extern "C" {
char* convertToTitle(int columnNumber);
}

std::string solution_c(int columnNumber) {
  return convertToTitle(columnNumber);
}
