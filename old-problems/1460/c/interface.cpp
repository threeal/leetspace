#include <vector>

extern "C" {
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize);
}

bool solution_c(std::vector<int> target, std::vector<int> arr) {
  return canBeEqual(target.data(), target.size(), arr.data(), arr.size());
}
