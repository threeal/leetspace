#include <vector>

extern "C" {
bool canMakeArithmeticProgression(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return canMakeArithmeticProgression(arr.data(), arr.size());
}
