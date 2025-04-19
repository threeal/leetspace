#include <string>

extern "C" {
char* getPermutation(int n, int k);
}

std::string solution_c(int n, int k) {
  return getPermutation(n, k);
}
