#include <vector>

extern "C" {
bool threeConsecutiveOdds(int* arr, int arrSize);
}

bool solution_c(std::vector<int> arr) {
  return threeConsecutiveOdds(arr.data(), arr.size());
}
