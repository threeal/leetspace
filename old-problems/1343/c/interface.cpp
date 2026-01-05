#include <vector>

extern "C" {
int numOfSubarrays(int* arr, int arrSize, int k, int threshold);
}

int solution_c(std::vector<int> arr, int k, int threshold) {
  return numOfSubarrays(arr.data(), arr.size(), k, threshold);
}
