#include <vector>

extern "C" {
int xorOperation(int n, int start);
}

int solution_c(int n, int start) {
  return xorOperation(n, start);
}
