#include <vector>

extern "C" {
long long maxSubarraySum(int* nums, int numsSize, int k);
}

long long solution_c(std::vector<int> nums, int k) {
  return maxSubarraySum(nums.data(), nums.size(), k);
}
