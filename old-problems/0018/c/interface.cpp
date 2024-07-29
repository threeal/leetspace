#include <cstring>
#include <vector>

extern "C" {
int** fourSum(
    int* nums, int numsSize, int target,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums, int target) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = fourSum(
      nums.data(), nums.size(), target, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
