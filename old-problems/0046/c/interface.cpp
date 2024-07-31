#include <cstring>
#include <vector>

extern "C" {
int** permute(
    int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = permute(
      nums.data(), nums.size(), &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
