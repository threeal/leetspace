#include <string>

extern "C" {
int minimumRecolors(char* blocks, int k);
}

int solution_c(std::string blocks, int k) {
  return minimumRecolors(blocks.data(), k);
}
