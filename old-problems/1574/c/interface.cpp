#include <vector>

extern "C" {
int findLengthOfShortestSubarray(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return findLengthOfShortestSubarray(arr.data(), arr.size());
}
