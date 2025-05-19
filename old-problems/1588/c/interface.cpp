#include <vector>

extern "C" {
int sumOddLengthSubarrays(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return sumOddLengthSubarrays(arr.data(), arr.size());
}
