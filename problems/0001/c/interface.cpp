#include <vector>

extern "C" {
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
}

std::vector<int> solution_c(std::vector<int>& nums, int target) {
  int ret_size;
  auto ret_ptr = twoSum(nums.data(), nums.size(), target, &ret_size);
  return std::vector<int>(ret_ptr, ret_ptr + ret_size);
}
