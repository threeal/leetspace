#include <string>

extern "C" {
char* getHappyString(int n, int k);
}

std::string solution_c(int n, int k) {
  return getHappyString(n, k);
}
