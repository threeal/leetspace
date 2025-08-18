#include <string>

extern "C" {
char* generateTheString(int n);
}

std::string solution_c(int n) {
  return generateTheString(n);
}
