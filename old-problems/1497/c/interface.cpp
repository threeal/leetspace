#include <vector>

extern "C" {
bool canArrange(int* arr, int arrSize, int k);
}

bool solution_c(std::vector<int> arr, int k) {
  return canArrange(arr.data(), arr.size(), k);
}
