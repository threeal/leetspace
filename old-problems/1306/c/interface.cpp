#include <vector>

extern "C" {
bool canReach(int* arr, int arrSize, int start);
}

bool solution_c(std::vector<int> arr, int start) {
  return canReach(arr.data(), arr.size(), start);
}
