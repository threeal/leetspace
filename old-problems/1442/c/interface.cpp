#include <vector>

extern "C" {
int countTriplets(int* arr, int arrSize);
}

int solution_c(std::vector<int> arr) {
  return countTriplets(arr.data(), arr.size());
}
