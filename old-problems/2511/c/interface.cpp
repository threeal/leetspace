#include <vector>

extern "C" {
int captureForts(int* forts, int fortsSize);
}

int solution_c(std::vector<int> forts) {
  return captureForts(forts.data(), forts.size());
}
