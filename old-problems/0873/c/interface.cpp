#include <vector>

extern "C" {
int lenLongestFibSubseq(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return lenLongestFibSubseq(arr.data(), arr.size());
}
