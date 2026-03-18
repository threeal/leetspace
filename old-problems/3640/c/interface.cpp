#include <vector>

extern "C" {
long long maxSumTrionic(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return maxSumTrionic(nums.data(), nums.size());
}
