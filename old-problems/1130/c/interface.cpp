#include <vector>

extern "C" {
int mctFromLeafValues(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return mctFromLeafValues(arr.data(), arr.size());
}
