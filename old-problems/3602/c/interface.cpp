#include <string>

extern "C" {
char* concatHex36(int n);
}

std::string solution_c(int n) {
  return concatHex36(n);
}
