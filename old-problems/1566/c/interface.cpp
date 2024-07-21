#include <vector>

extern "C" {
bool containsPattern(int* arr, int arrSize, int m, int k);
}

bool solution_c(std::vector<int> arr, int m, int k) {
  return containsPattern(arr.data(), arr.size(), m, k);
}
