#include <vector>

extern "C" {
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> temperatures) {
  int returnSize;
  dailyTemperatures(temperatures.data(), temperatures.size(), &returnSize);
  return temperatures;
}
