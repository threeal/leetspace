#include <string>

extern "C" {
char* convertToBase7(int num);
}

std::string solution_c(int num) {
  return convertToBase7(num);
}
