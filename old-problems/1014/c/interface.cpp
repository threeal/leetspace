#include <vector>

extern "C" {
int maxScoreSightseeingPair(int* values, int valuesSize);
}

int solution_c(std::vector<int> values) {
  return maxScoreSightseeingPair(values.data(), values.size());
}
