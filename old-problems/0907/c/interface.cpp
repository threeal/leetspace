#include <vector>

extern "C" {
int sumSubarrayMins(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return sumSubarrayMins(arr.data(), arr.size());
}
