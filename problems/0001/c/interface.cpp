#include <internal.hpp>
#include <vector>

extern "C" {
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
}

template <>
std::vector<int> solution_c(const std::vector<int>& nums, const int& target) {
  auto nums_copy = nums;
  int ret_size;
  auto ret_ptr = twoSum(nums_copy.data(), nums_copy.size(), target, &ret_size);
  return std::vector<int>(ret_ptr, ret_ptr + ret_size);
}
