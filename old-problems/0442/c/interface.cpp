#include <cstring>
#include <vector>

extern "C" {
int* findDuplicates(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  const auto returnData = findDuplicates(nums.data(), nums.size(), &returnSize);

  nums.resize(returnSize);
  std::memcpy(nums.data(), returnData, sizeof(int) * returnSize);

  return nums;
}
