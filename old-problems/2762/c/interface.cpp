#include <vector>

extern "C" {
long long continuousSubarrays(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return continuousSubarrays(nums.data(), nums.size());
}
