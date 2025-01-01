#include <vector>

extern "C" {
long long maximumSubarraySum(int* nums, int numsSize, int k);
}

long long solution_c(std::vector<int> nums, int k) {
  return maximumSubarraySum(nums.data(), nums.size(), k);
}
