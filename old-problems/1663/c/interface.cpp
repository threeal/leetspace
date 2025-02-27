#include <string>

extern "C" {
char* getSmallestString(int n, int k);
}

std::string solution_c(int n, int k) {
  return getSmallestString(n, k);
}
