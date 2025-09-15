#include <cstring>
#include <vector>

extern "C" {
char kthCharacter(int k);
}

char solution_c(int k) {
  return kthCharacter(k);
}
