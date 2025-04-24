#include <cstring>
#include <vector>

extern "C" {
int** subsetsWithDup(
    int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      subsetsWithDup(nums.data(), nums.size(), &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
