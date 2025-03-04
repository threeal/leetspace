#include <vector>

extern "C" {
int numOfSubarrays(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return numOfSubarrays(arr.data(), arr.size());
}
