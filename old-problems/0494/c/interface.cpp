#include <vector>

extern "C" {
int findTargetSumWays(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return findTargetSumWays(nums.data(), nums.size(), target);
}
