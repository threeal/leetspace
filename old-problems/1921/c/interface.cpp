#include <vector>

extern "C" {
int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize);
}

int solution_c(std::vector<int> dist, std::vector<int> speed) {
  return eliminateMaximum(dist.data(), dist.size(), speed.data(), speed.size());
}
