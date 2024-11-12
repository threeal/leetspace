#include <vector>

extern "C" {
int largestCombination(int* candidates, int candidatesSize);
}

int solution_c(std::vector<int> candidates) {
  return largestCombination(candidates.data(), candidates.size());
}
