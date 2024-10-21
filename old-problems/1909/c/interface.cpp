#include <vector>

extern "C" {
bool canBeIncreasing(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return canBeIncreasing(nums.data(), nums.size());
}
