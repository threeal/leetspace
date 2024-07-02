#include <vector>

extern "C" {
bool checkSubarraySum(int* nums, int numsSize, int k);
}

bool solution_c(std::vector<int> nums, int k) {
  return checkSubarraySum(nums.data(), nums.size(), k);
}
