#include <vector>

extern "C" {
int findLucky(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return findLucky(arr.data(), arr.size());
}
