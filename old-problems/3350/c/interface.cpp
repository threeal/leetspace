#include <vector>

extern "C" {
int maxIncreasingSubarrays(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxIncreasingSubarrays(nums.data(), nums.size());
}
