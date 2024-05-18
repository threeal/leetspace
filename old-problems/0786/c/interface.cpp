#include <cstring>
#include <vector>

extern "C" {
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> arr, int k) {
  int returnSize{};
  const auto returnData{kthSmallestPrimeFraction(arr.data(), arr.size(), k, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));
  return output;
}
