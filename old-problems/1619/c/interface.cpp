#include <vector>

extern "C" {
double trimMean(int* arr, int arrSize);
}

double solution_c(std::vector<int> arr) {
  return trimMean(arr.data(), arr.size());
}
