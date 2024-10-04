#include <vector>

extern "C" {
int longestSubarray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestSubarray(nums.data(), nums.size());
}
