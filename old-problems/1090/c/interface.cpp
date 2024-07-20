#include <vector>

extern "C" {
int largestValsFromLabels(
    int* values, int valuesSize, int* labels, int labelsSize,
    int numWanted, int useLimit);
}

int solution_c(
    std::vector<int> values, std::vector<int> labels,
    int numWanted, int useLimit) {
  return largestValsFromLabels(
      values.data(), values.size(), labels.data(), labels.size(),
      numWanted, useLimit);
}
