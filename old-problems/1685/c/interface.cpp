#include <cstring>
#include <vector>

extern "C" {
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  const auto data = getSumAbsoluteDifferences(nums.data(), nums.size(), &returnSize);

  nums.resize(returnSize);
  std::memcpy(nums.data(), data, returnSize * sizeof(int));
  return nums;
}
