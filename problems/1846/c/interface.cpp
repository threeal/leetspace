#include <vector>

extern "C" {
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return maximumElementAfterDecrementingAndRearranging(arr.data(), arr.size());
}
