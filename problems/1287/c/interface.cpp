#include <vector>

extern "C" {
int findSpecialInteger(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return findSpecialInteger(arr.data(), arr.size());
}
