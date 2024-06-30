#include <vector>

extern "C" {
int addRungs(int* rungs, int rungsSize, int dist);
}

int solution_c(std::vector<int> rungs, int dist) {
  return addRungs(rungs.data(), rungs.size(), dist);
}
