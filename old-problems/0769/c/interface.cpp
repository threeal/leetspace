#include <vector>

extern "C" {
int maxChunksToSorted(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return maxChunksToSorted(arr.data(), arr.size());
}
