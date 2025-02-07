#include <vector>

extern "C" {
int longestMonotonicSubarray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestMonotonicSubarray(nums.data(), nums.size());
}
