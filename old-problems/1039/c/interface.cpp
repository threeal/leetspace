#include <vector>

extern "C" {
int minScoreTriangulation(int* values, int valuesSize);
}

int solution_c(std::vector<int> values) {
  return minScoreTriangulation(values.data(), values.size());
}
