#include <vector>

extern "C" {
int longestSubarray(int* nums, int numsSize, int limit);
}

int solution_c(std::vector<int> nums, int limit) {
  return longestSubarray(nums.data(), nums.size(), limit);
}
