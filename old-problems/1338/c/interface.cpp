#include <vector>

extern "C" {
int minSetSize(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return minSetSize(arr.data(), arr.size());
}
