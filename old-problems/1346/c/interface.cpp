#include <vector>

extern "C" {
bool checkIfExist(int* arr, int arrSize);
}

bool solution_c(std::vector<int> arr) {
  return checkIfExist(arr.data(), arr.size());
}
