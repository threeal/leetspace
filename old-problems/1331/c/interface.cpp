#include <cstring>
#include <vector>

extern "C" {
int* arrayRankTransform(int* arr, int arrSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> arr) {
  int returnSize;
  const auto returnData =
      arrayRankTransform(arr.data(), arr.size(), &returnSize);

  arr.resize(returnSize);
  std::memcpy(arr.data(), returnData, returnSize * sizeof(int));
  return arr;
}
