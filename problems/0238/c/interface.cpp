#include <cstring>
#include <vector>

extern "C" {
int* productExceptSelf(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  const auto returnData = productExceptSelf(nums.data(), nums.size(), &returnSize);

  nums.resize(returnSize);
  std::memcpy(nums.data(), returnData, sizeof(int) * returnSize);

  return nums;
}
