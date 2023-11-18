#include <vector>

extern "C" {
int getWinner(int* arr, int arrSize, int k);
}

int solution_c(std::vector<int> arr, int k) {
  return getWinner(arr.data(), arr.size(), k);
}
