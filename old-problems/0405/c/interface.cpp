#include <string>

extern "C" {
char* toHex(int num);
}

std::string solution_c(int num) {
  return toHex(num);
}
