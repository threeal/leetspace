#include <vector>

extern "C" {
int maxSumAfterPartitioning(int* arr, int arrSize, int k);
}

int solution_c(std::vector<int> arr, int k) {
  return maxSumAfterPartitioning(arr.data(), arr.size(), k);
}
