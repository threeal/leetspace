#include <vector>

extern "C" {
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c);
}

int solution_c(std::vector<int> arr, int a, int b, int c) {
  return countGoodTriplets(arr.data(), arr.size(), a, b, c);
}
