#include <vector>

extern "C" {
int maxSatisfaction(int* satisfaction, int satisfactionSize);
}

int solution_c(std::vector<int> satisfaction) {
  return maxSatisfaction(satisfaction.data(), satisfaction.size());
}
