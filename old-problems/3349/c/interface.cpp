#include <vector>

extern "C" {
bool hasIncreasingSubarrays(int* nums, int numsSize, int k);
}

bool solution_c(std::vector<int> nums, int k) {
  return hasIncreasingSubarrays(nums.data(), nums.size(), k);
}
