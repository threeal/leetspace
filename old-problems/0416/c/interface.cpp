#include <vector>

extern "C" {
bool canPartition(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return canPartition(nums.data(), nums.size());
}
