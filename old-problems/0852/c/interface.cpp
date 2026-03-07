#include <vector>

extern "C" {
int peakIndexInMountainArray(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return peakIndexInMountainArray(arr.data(), arr.size());
}
